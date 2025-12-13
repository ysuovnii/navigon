#include "./class/map.hpp"


Map::Map(float width, float height, float tileSize)
    : width(width), height(height), tileSize(tileSize)
{
    grid.resize(height, std::vector<float>(width, 1));

    tile.setSize(sf::Vector2f(tileSize, tileSize));

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    generateMaze();
}

void Map::generateMaze() {
    for (float y = 0; y < height; y++)
        for (float x = 0; x < width; x++)
            grid[y][x] = 1;

    carvePath(1, 1);
}

void Map::carvePath(float x, float y) {
    static int directions[4][2] = {
        { 0, -2 }, { 0, 2 }, { -2, 0 }, { 2, 0 }
    };

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::shuffle(std::begin(directions), std::end(directions), gen);

    for (auto& dir : directions) {
        int nx = x + dir[0];
        int ny = y + dir[1];

        if (nx > 0 && ny > 0 && nx < width - 1 && ny < height - 1) {
            if (grid[ny][nx] == 1) {
                grid[y + dir[1] / 2][x + dir[0] / 2] = 0;
                grid[ny][nx] = 0;
                carvePath(nx, ny);
            }
        }
    }
}


void Map::draw(sf::RenderWindow& window) {
    for (float y = 0; y < height; y++) {
        for (float x = 0; x < width; x++) {

            tile.setPosition({x * tileSize, y * tileSize});

            if (grid[y][x] == 1)
                tile.setFillColor(sf::Color(40, 40, 40)); 
            else
                tile.setFillColor(sf::Color(200, 200, 200)); 

            window.draw(tile);
        }
    }
}

bool Map::isWallAtPixel(float px, float py) {
    int x = static_cast<int>(px) / tileSize;
    int y = static_cast<int>(py) / tileSize;

    if (x < 0 || y < 0 || x >= width || y >= height)
        return true;

    return grid[y][x] == 1;
}



