#ifndef CIRCLE_HPP 
#define CIRCLE_HPP

#include <SFML/Graphics.hpp>

class Circle {
public: 
    sf::CircleShape circle;
    sf::CircleShape visionCircle;
    float speed;
    float visionRadius;

    Circle(float initX, float initY, float speed, float radius, float visionRadius, sf::Color color);
    
    void makeVisionCircle(float x, float y);
    void charKeyControl(sf::Vector2f& move);

    void enemyCollision();
    void isInvisible(); 
};

#endif