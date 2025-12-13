#ifndef CIRCLE_HPP 
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : Shape {
public: 
    sf::CircleShape circle;
    sf::CircleShape visionCircle;

    Circle(float initX, float initY, float speed, float radius, float visionRadius, sf::Color color);
    
    void makeVisionCircle(float x, float y);
    void arrKeyControl();
    void charKeyControl();

    void enemyCollision();
    void isInvisible(); 
};

#endif