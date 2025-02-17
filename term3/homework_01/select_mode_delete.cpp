#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <algorithm>
#include "draggable.cpp"

class Ball
{
public:
    sf::CircleShape shape;
    sf::Color color;
    bool isSelected = false;

    Ball(float radius, sf::Vector2f position, sf::Color color)
    {
        shape.setRadius(radius);
        shape.setPosition(position);
        shape.setFillColor(color);
        this->color = color;
    }

    void setColor(sf::Color newColor)
    {
        shape.setFillColor(newColor);
        color = newColor;
    }

    void draw(sf::RenderWindow& window) const
    {
        window.draw(shape);
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Select Move Delete");
    window.setFramerateLimit(60);

    std::list<Ball> balls;
    std::vector<Ball*> selectedBalls;
    sf::RectangleShape selectionRect;
    selectionRect.setFillColor(sf::Color(255, 255, 255, 50));
    selectionRect.setOutlineColor(sf::Color::White);
    selectionRect.setOutlineThickness(1.0f);

    bool isSelecting = false;
    sf::Vector2f selectionStart;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

                    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                    {
                        for (auto& ball : balls)
                        {
                            ball.isSelected = false;
                        }
                        selectedBalls.clear();
                    }

                    bool clickedOnBall = false;
                    for (auto& ball : balls)
                    {
                        if (ball.shape.getGlobalBounds().contains(mousePos))
                        {
                            ball.isSelected = !ball.isSelected;
                            if (ball.isSelected)
                            {
                                selectedBalls.push_back(&ball);
                            }
                            else
                            {
                                selectedBalls.erase(std::remove(selectedBalls.begin(), selectedBalls.end(), &ball), selectedBalls.end());
                            }
                            clickedOnBall = true;
                            break;
                        }
                    }

                    if (!clickedOnBall)
                    {
                        isSelecting = true;
                        selectionStart = mousePos;
                        selectionRect.setPosition(selectionStart);
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    isSelecting = false;
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

                    for (auto& ball : balls)
                    {
                        if (selectionRect.getGlobalBounds().contains(ball.shape.getPosition()))
                        {
                            ball.isSelected = true;
                            selectedBalls.push_back(&ball);
                        }
                    }
                }
            }

            if (event.type == sf::Event::MouseMoved)
            {
                if (isSelecting)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                    selectionRect.setSize(mousePos - selectionStart);
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Delete)
                {
                    for (auto& ball : selectedBalls)
                    {
                        balls.remove_if([&](Ball& b) { return &b == ball; });
                    }
                    selectedBalls.clear();
                }

                if (event.key.code == sf::Keyboard::Space)
                {
                    for (auto& ball : selectedBalls)
                    {
                        ball->setColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
                    }
                }
            }
        }

        window.clear();
        for (auto& ball : balls)
        {
            ball.draw(window);
        }
        if (isSelecting)
        {
            window.draw(selectionRect);
        }
        window.display();
    }

    return 0;
}