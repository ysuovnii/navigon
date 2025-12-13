#ifndef CIRCLE_HPP 
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : Shape {
public: 
    sf::CircleShape circle;
    Circle(float speed, float visibleArea);
    void arrKeyControl();
    void charKeyControl();
    void enemyCollision();
    void isInvisible(); // power
};

#endif