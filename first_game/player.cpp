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
Player::Player() : a(1), s(7), d(5), w(3), pressed(0), move_x(0), move_y(0) {
	playerSprite.setTextureRect(sf::IntRect(0, 0, 26, 26));
	playerSprite.setScale(1.2f, 1.2f);
}

// Member function to set player sprite
void Player::sp(sf::Texture& sprite) {
	playerSprite.setTexture(sprite);
}

// Member function to update player state
void Player::update() {
	rect.left += move_x;
	rect.top += move_y;

	if (rect.left < -10) {
		rect.left = 640;
	}
	if (rect.left > 640) {
		rect.left = -10;
	}

	if (move_x > 0) {
		if (pressed == 5) {
			d++;
			if (d > 6) {
				d = 5;
			}
			pressed = 0;
		}
		playerSprite.setTextureRect(sf::IntRect(d * 26, 0, 26, 26));
		pressed++;
	}
	else if (move_x < 0) {
		if (pressed == 5) {
			a++;
			if (a > 2) {
				a = 1;
			}
			pressed = 0;
		}
		playerSprite.setTextureRect(sf::IntRect(a * 26, 0, 26, 26));
		pressed++;
	}
	else if (move_y < 0) {
		if (pressed == 5) {
			w++;
			if (w > 4) {
				w = 3;
			}
			pressed = 0;
		}
		playerSprite.setTextureRect(sf::IntRect(w * 26, 0, 26, 26));
		pressed++;
	}
	else if (move_y > 0) {
		if (pressed == 5) {
			s++;
			if (s > 8) {
				s = 7;
			}
			pressed = 0;
		}
		playerSprite.setTextureRect(sf::IntRect(s * 26, 0, 26, 26));
		pressed++;
	}

	playerSprite.setPosition(rect.left, rect.top);
	move_x = 0;
	move_y = 0;
}
