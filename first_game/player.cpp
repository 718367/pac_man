#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>
#include "Menu.h"
#include "player.h"
#include "maze.h"
// Constructor
Player::Player() : a(1), s(7), d(5), w(3), moveSpeed(2), move_x(0), move_y(0) {
	playerSprite.setTextureRect(sf::IntRect(0, 0, 26, 26));
	playerSprite.setScale(1.2f, 1.2f);
}

// Member function to set player sprite
void Player::sp(sf::Texture& sprite) {
	playerSprite.setTexture(sprite);
}

// Member function to update player state
void Player::update() {

	// Update player's position based on movement
	rect.left += move_x;
	rect.top += move_y;

	// Check if player has reached boundaries
	if (rect.left < -10) {
		rect.left = 640;
	}
	if (rect.left > 640) {
		rect.left = -10;
	}
	// Update elapsed time
	float deltaTime = clock.restart().asSeconds();

	// Accumulate elapsed frame time
	elapsedFrameTime += deltaTime;
	if (elapsedFrameTime >= frameTime) {

		// Update sprite animation
		updateAnimation();

		elapsedFrameTime = 0.0f;
	}
	// Set player's position
	playerSprite.setPosition(rect.left, rect.top);
}



void Player::updateAnimation()
{
	// move right
	if (move_x > 0) {
		d++;
		if (d > 6) {
			d = 5;
		}
		playerSprite.setTextureRect(sf::IntRect(d * 26, 0, 26, 26));
	}
	// move left
	else if (move_x < 0) {
		a++;
		if (a > 2) {
			a = 1;
		}
		playerSprite.setTextureRect(sf::IntRect(a * 26, 0, 26, 26));
	}
	// move up
	if (move_y > 0) {
		s++;
		if (s > 8) {
			s = 7;
		}
		playerSprite.setTextureRect(sf::IntRect(s * 26, 0, 26, 26));
	}
	// move down
	else if (move_y < 0) {
		w++;
		if (w > 4) {
			w = 3;
		}
		playerSprite.setTextureRect(sf::IntRect(w * 26, 0, 26, 26));
	}
}




