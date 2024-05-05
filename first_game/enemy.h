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
class enemy
{
public:
    // Constructor
    enemy();

    // Method to update enemy position
    void update();

    // Method to draw enemy on screen
    void draw(sf::RenderWindow& window);

private:
    sf::Sprite nemySprite;
    sf::Vector2f position;
    float speed;
};


