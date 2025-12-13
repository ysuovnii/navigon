#include "circle.hpp"

void Circle::arrKeyControl() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        circle.move({0, -speed});
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        circle.move({-speed, 0});
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        circle.move({0, speed});
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        circle.move({speed, 0});
    } 
}

void Circle::charKeyControl() { 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        circle.move({0, -speed});
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        circle.move({-speed, 0});
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        circle.move({0, speed});
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        circle.move({speed, 0});
    } 
}
