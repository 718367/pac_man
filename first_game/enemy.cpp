#include "enemy.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>
#include "Menu.h"
#include "player.h"
#include "maze.h"
#include "game.h"
 
using namespace std;
using namespace sf;

enemy::enemy()
{

}

void enemy::draw(sf::RenderWindow& window) {
    window.draw(nemySprite);
}