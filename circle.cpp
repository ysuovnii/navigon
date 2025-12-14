#include "./class/circle.hpp"

Circle::Circle(float initX, float initY, float speed, float radius, float visionRadius, sf::Color color) {
    this->speed = speed;
    this->visionRadius = visionRadius;

    circle.setPosition({initX, initY});
    circle.setRadius(radius);
    circle.setOrigin({radius, radius});
    circle.setFillColor(color);

    makeVisionCircle(initX, initY);
}

void Circle::makeVisionCircle(float initX, float initY) {
    
    visionCircle.setPosition({initX, initY});
    visionCircle.setRadius(visionRadius);
    visionCircle.setOrigin({visionRadius, visionRadius});
    visionCircle.setFillColor(sf::Color::Transparent);
    visionCircle.setOutlineThickness(2.f);
    visionCircle.setOutlineColor(sf::Color::White);
}

void Circle::charKeyControl(sf::Vector2f& move) {
    move.x = 0.f;
    move.y = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) move.y -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) move.y += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) move.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) move.x += speed;
}

