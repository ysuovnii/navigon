#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>


bool circleRectCollision(const sf::Vector2f& cPos, float radius, const sf::FloatRect& rect) {
    float left   = rect.position.x;
    float top    = rect.position.y;
    float right  = rect.position.x + rect.size.x;
    float bottom = rect.position.y + rect.size.y;

    float closestX = std::clamp(cPos.x, left, right);
    float closestY = std::clamp(cPos.y, top, bottom);

    float dx = cPos.x - closestX;
    float dy = cPos.y - closestY;

    return (dx * dx + dy * dy) < (radius * radius);
}

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Navigon");
    window.setFramerateLimit(120);

    sf::View camera;
    camera.setSize({800.f, 800.f});

    sf::CircleShape player(25.f);
    player.setOrigin({25.f, 25.f});
    player.setFillColor(sf::Color::Red);
    player.setPosition({200.f, 200.f});

    float playerSpeed = 250.f;

    std::vector<sf::RectangleShape> walls;

    auto makeWall = [&](sf::Vector2f size, sf::Vector2f pos) {
        sf::RectangleShape wall(size);
        wall.setPosition(pos);
        wall.setFillColor(sf::Color::White);
        walls.push_back(wall);
    };


    makeWall({600.f, 6.f}, {100.f, 100.f});
    makeWall({600.f, 6.f}, {100.f, 700.f});
    makeWall({6.f, 600.f}, {100.f, 100.f});
    makeWall({6.f, 600.f}, {700.f, 100.f});

    makeWall({300.f, 6.f}, {150.f, 250.f});
    makeWall({6.f, 300.f}, {450.f, 250.f});
    makeWall({250.f, 6.f}, {200.f, 450.f});


    sf::Clock clock;

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float dt = clock.restart().asSeconds();

        sf::Vector2f movement(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) movement.y -= playerSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) movement.y += playerSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) movement.x -= playerSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) movement.x += playerSpeed;

        sf::Vector2f nextPosX = player.getPosition() + sf::Vector2f(movement.x * dt, 0.f);
        bool blockX = false;

        for (auto& wall : walls) {
            if (circleRectCollision(nextPosX, player.getRadius(), wall.getGlobalBounds())) {
                blockX = true;
                break;
            }
        }

        if (!blockX)
            player.setPosition(nextPosX);

        sf::Vector2f nextPosY = player.getPosition() + sf::Vector2f(0.f, movement.y * dt);
        bool blockY = false;

        for (const auto& wall : walls) {
            if (circleRectCollision(nextPosY, player.getRadius(), wall.getGlobalBounds())) {
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

        for (const auto& wall : walls)
            window.draw(wall);

        window.draw(player);
        window.display();
    }

    return 0;
}
