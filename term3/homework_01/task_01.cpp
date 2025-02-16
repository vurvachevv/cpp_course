#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Rotating Square");
    sf::RectangleShape square(sf::Vector2f(100.0f, 100.0f));
    square.setFillColor(sf::Color::Green);
    square.setPosition(350.0f, 250.0f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        square.rotate(1.0f);

        window.clear();
        window.draw(square);
        window.display();
    }

    return 0;
}