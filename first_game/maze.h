#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include <map>

extern float collisionThinkness;
const int num_ofCollisions = 150;
const int num_of_Coins = 676;

class maze {
public:
    sf::Texture texture;
    sf::Sprite background;
    sf::RectangleShape blocks[num_ofCollisions];
    std::map<int, char> blockMap;
    const float collisionThickness = 2.0f;
    const int noCollisions = 150;
    const int noCoins = 676;

    maze() {}

    bool loadMapTexture(const std::string& filename);
    void drawPoints(sf::Sprite points[], sf::Texture& point);
    void drawCollision(sf::RectangleShape& block, float X, float Y, float X_position, float Y_position);
    void drawCollision2(sf::RectangleShape block, Player& player, char dr);
    void mapCollision(sf::RectangleShape blocks[], std::map<int, char>& map);
    bool isEmptyPlace(int xIndex, int yIndex);
    void draw(sf::RenderWindow& window);
};


