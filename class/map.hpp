#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

class Map {
public:
    Map(float width, float height, float tileSize);

    void generateMaze();          
    void draw(sf::RenderWindow& window);
    bool isWall(float x, float y) ;
    bool isWallAtPixel(float px, float py);

private:
    float width;
    float height;
    float tileSize;

    std::vector<std::vector<float>> grid; 

    sf::RectangleShape tile;

    void carvePath(float x, float y); 
};

#endif
