#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

bool circleRectCollision(const sf::Vector2f &cPos, float radius, const sf::FloatRect &rect)
{
    float left = rect.position.x;
    float top = rect.position.y;
    float right = rect.position.x + rect.size.x;
    float bottom = rect.position.y + rect.size.y;

    float closestX = std::clamp(cPos.x, left, right);
    float closestY = std::clamp(cPos.y, top, bottom);

    float dx = cPos.x - closestX;
    float dy = cPos.y - closestY;

    return (dx * dx + dy * dy) < (radius * radius);
}

void makeRing(
    std::vector<sf::RectangleShape> &walls,
    sf::Vector2f center,
    float radius,
    float thickness,
    int segments,
    const std::set<int> &gaps)
{
    constexpr float PI = 3.14159265359f;
    float angleStep = 2.f * PI / segments;

    for (int i = 0; i < segments; i++)
    {
        if (gaps.count(i))
            continue;

        float angle = i * angleStep;

        sf::RectangleShape wall;
        wall.setSize({radius * angleStep, thickness});
        wall.setOrigin({0.f, thickness / 2.f});
        wall.setPosition({center.x + std::cos(angle) * radius,
                          center.y + std::sin(angle) * radius});
        wall.setRotation(sf::degrees(angle * 180.f / PI));
        wall.setFillColor(sf::Color::White);

        walls.push_back(wall);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Navigon");
    window.setFramerateLimit(120);

    sf::View camera;
    camera.setSize({800.f, 800.f});

    sf::CircleShape player(25.f);
    player.setOrigin({25.f, 25.f});
    player.setRadius(10);
    player.setFillColor(sf::Color::Red);
    float playerSpeed = 250.f;

    std::vector<sf::RectangleShape> walls;

    sf::Vector2f mazeCenter(1000.f, 1000.f);

    makeRing(walls, mazeCenter, 800.f, 10.f, 90, {5, 30});
    makeRing(walls, mazeCenter, 650.f, 10.f, 80, {12, 40});
    makeRing(walls, mazeCenter, 500.f, 10.f, 70, {18, 55});
    makeRing(walls, mazeCenter, 350.f, 10.f, 60, {10, 35});
    makeRing(walls, mazeCenter, 200.f, 10.f, 50, {22});

    player.setPosition({900, 900});

    sf::Clock clock;

    while (window.isOpen())
    {
        while (std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float dt = clock.restart().asSeconds();

        sf::Vector2f movement(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            movement.y -= playerSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            movement.y += playerSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            movement.x -= playerSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            movement.x += playerSpeed;

        sf::Vector2f nextPosX = player.getPosition() + sf::Vector2f(movement.x * dt, 0.f);
        bool blockX = false;
        for (auto &wall : walls)
        {
            if (circleRectCollision(nextPosX, player.getRadius(), wall.getGlobalBounds()))
            {
                blockX = true;
                break;
            }
        }
        if (!blockX)
            player.setPosition(nextPosX);

        sf::Vector2f nextPosY = player.getPosition() + sf::Vector2f(0.f, movement.y * dt);
        bool blockY = false;
        for (auto &wall : walls)
        {
            if (circleRectCollision(nextPosY, player.getRadius(), wall.getGlobalBounds()))
            {
                blockY = true;
                break;
            }
        }
        if (!blockY)
            player.setPosition(nextPosY);

        sf::Vector2f camPos = camera.getCenter();
        sf::Vector2f target = player.getPosition();
        camPos += (target - camPos) * 6.f * dt;
        camera.setCenter(camPos);
        window.setView(camera);

        window.clear(sf::Color::Black);
        for (const auto &wall : walls)
            window.draw(wall);
        window.draw(player);
        window.display();
    }

    return 0;
}
