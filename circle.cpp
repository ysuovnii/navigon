#include "./class/circle.hpp"

Circle::Circle(float initX, float initY, float speed, float visibleRadius, sf::Color color) {
    this->speed = speed;
    this->visibleRadius = visibleRadius;
    circle.setPosition({initX, initY});
    circle.setRadius(visibleRadius/2);
    circle.setFillColor(color);
    makeVisionCircle();
}

void Circle::makeVisionCircle() {
    sf::Vector2f pos = circle.getPosition();
    visionCircle.setRadius(visibleRadius);
    visionCircle.setFillColor(sf::Color::White);
    visionCircle.setPosition({pos.x, pos.y});

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
