
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <map>
#include <iterator>
using namespace std;
using namespace sf;

// Class Definition
class Player {

public:
	// Constructor
	Player();

	// Member function to set player sprite
	void sp(sf::Texture& sprite);

	// Member function to update player state
	void update();

	sf::Sprite playerSprite;
	int a, s, d, w, pressed;
	sf::FloatRect rect;
	float move_x, move_y;
};


