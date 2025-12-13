#include "config.hpp"
#include "shape.hpp"
#include "circle.hpp"

int main() { 
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "Navigon");
    window.setFramerateLimit(FPS);


    while(window.isOpen()) {
        while(std::optional event = window.pollEvent()) {
            if(event->is<sf::Event::Closed>()) window.close();
        }




        window.clear();
        window.display();
    }

    return 0;
}