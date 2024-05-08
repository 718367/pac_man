#ifndef GAME_H
#define GAME_H

#pragma once
#include <iostream>

#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>
#include "player.h"
#include "maze.h"

class game {
public:
    game();

    int level1(sf::RenderWindow& window , int& score);

private:
    Text level;
    Text scoreText;
    Font font;
    Texture playerTexture;
    Player player;
    Texture sPo, bPo;
    maze maze;
    std::vector<sf::Sprite> points;
    std::vector<sf::RectangleShape> blocks;

    std::map<int, char> blockMap;

    void playerMovement();
    void playerCollisions();
    void drawObjects(sf::RenderWindow& window, int& s);
    const int no_Collisions = 150;
    const int no_Coins = 676;
};

#endif // GAME_H

/*Sprite points[no_Coins];
RectangleShape blocks[no_Collisions];*/