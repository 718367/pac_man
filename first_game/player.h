#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <iterator>
using namespace std;
using namespace sf;
// Class Definition
class Player {

public:
	int moveSpeed;
	int a, s, d, w;
	float move_x, move_y;
	float frameTime = 0.1f; // Time (in seconds) between sprite frame changes
	float elapsedFrameTime = 0.0f;
	Clock clock;
	Sprite playerSprite;
	FloatRect rect;

	// Constructor
	Player();

	// Member function to set player sprite
	void sp(sf::Texture& sprite);

	// Member function to update player state
	void update();

	void updateAnimation();

};


