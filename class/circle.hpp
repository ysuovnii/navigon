#ifndef CIRCLE_HPP 
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : Shape {
public: 
    sf::CircleShape circle;
    sf::CircleShape visionCircle;

    Circle(float initX, float initY, float speed, float visionRadius, sf::Color color);
    
    void makeVisionCircle();
    void arrKeyControl();
    void charKeyControl();

    void enemyCollision();
    void isInvisible(); 
};

#endif