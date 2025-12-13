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

void Circle::arrKeyControl() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        circle.move({0, -speed});
        visionCircle.move({0, -speed});
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        circle.move({-speed, 0});
        visionCircle.move({-speed, 0});
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        circle.move({0, speed});
        visionCircle.move({0, speed});
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        circle.move({speed, 0});
        circle.move({speed, 0});
    } 
}

void Circle::charKeyControl() { 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        circle.move({0, -speed});
        visionCircle.move({0, -speed});
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        circle.move({-speed, 0});
        visionCircle.move({-speed, 0});
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        circle.move({0, speed});
        visionCircle.move({0, speed});
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        circle.move({speed, 0});
        visionCircle.move({speed, 0});
    } 
}
