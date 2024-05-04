#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>
#include "Menu.h"
#include "player.h"
#include "maze.h"
class game
{
public:
    game();
    void gamePlayPage(RenderWindow& window);
};

