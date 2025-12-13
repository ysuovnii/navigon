#include "./class/config.hpp"
#include "./class/shape.hpp"
#include "./class/circle.hpp"
#include "./class/map.hpp"

int main() { 
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "Navigon");
    window.setFramerateLimit(FPS);
    
    Map map(51, 51, 16);
    
    Circle main(100, 100, 10, 25, 100, sf::Color::Red);
    
    while(window.isOpen()) {
        while(std::optional event = window.pollEvent()) {
            if(event->is<sf::Event::Closed>()) window.close();
        }
        
        main.charKeyControl();

        window.clear(sf::Color::Black);
        map.draw(window);
        window.draw(main.visionCircle);
        window.draw(main.circle);
        window.display();

    }

    return 0;
}