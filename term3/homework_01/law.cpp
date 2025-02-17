#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
'''Закон Кулона'''

struct Ball
{
    sf::CircleShape shape;
    float mass;
    float charge;
    sf::Vector2f velocity;
};

float distance(const sf::Vector2f& a, const sf::Vector2f& b)
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    sf::RenderWindow window(sf::VideoMode(800, 600), "N-Body Problem");
    window.setFramerateLimit(60);

    std::vector<Ball> balls;
    for (int i = 0; i < 10; ++i)
    {
        Ball ball;
        ball.shape.setRadius(10.0f);
        ball.shape.setPosition(rand() % 700, rand() % 500);
        ball.mass = rand() % 10 + 1;
        ball.charge = (rand() % 2 == 0) ? 1.0f : -1.0f;
        ball.shape.setFillColor(ball.charge > 0 ? sf::Color::Red : sf::Color::Blue);
        ball.velocity = sf::Vector2f(0.0f, 0.0f);
        balls.push_back(ball);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (auto& ball : balls)
        {
            sf::Vector2f force(0.0f, 0.0f);
            for (auto& other : balls)
            {
                if (&ball == &other) continue;

                float dist = distance(ball.shape.getPosition(), other.shape.getPosition());
                if (dist < 20.0f) continue;

                float f = (ball.charge * other.charge) / dist;
                sf::Vector2f direction = other.shape.getPosition() - ball.shape.getPosition();
                direction /= dist;
                force += direction * f;
            }

            ball.velocity += force / ball.mass;
            ball.shape.move(ball.velocity);
        }

        for (auto& ball : balls)
        {
            sf::Vector2f pos = ball.shape.getPosition();
            if (pos.x < 0 || pos.x > 800 - 20) ball.velocity.x *= -1;
            if (pos.y < 0 || pos.y > 600 - 20) ball.velocity.y *= -1;
        }

        window.clear();
        for (auto& ball : balls)
        {
            window.draw(ball.shape);
        }
        window.display();
    }
}