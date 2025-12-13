#include "./class/config.hpp"
#include "./class/shape.hpp"
#include "./class/circle.hpp"
#include "./class/map.hpp"

bool collides(Map& map, sf::CircleShape& player, sf::Vector2f move) {
    sf::Vector2f center = player.getPosition() + move;
    float r = player.getRadius();

    return
        map.isWallAtPixel(center.x - r, center.y - r) ||
        map.isWallAtPixel(center.x + r, center.y - r) ||
        map.isWallAtPixel(center.x - r, center.y + r) ||
        map.isWallAtPixel(center.x + r, center.y + r);
}

int main() { 
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "Navigon");
    window.setFramerateLimit(FPS);
    
    Map map(51, 51, 16);    
    Circle main(100, 100, 10, 25, 100, sf::Color::Red);
    
    while(window.isOpen()) {
        while(std::optional event = window.pollEvent()) {
            if(event->is<sf::Event::Closed>()) window.close();
        }

        sf::Vector2f move(0.f, 0.f);
        main.charKeyControl(move);

        if (!collides(map, main.circle, move)) {
            main.circle.move(move);
            main.visionCircle.move(move);
        }

        window.clear(sf::Color::Black);
        map.draw(window);
        window.draw(main.visionCircle);
        window.draw(main.circle);
        window.display();
    }

    return 0;
}
