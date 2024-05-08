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
const int no_Collisions = 150;
const int no_Coins = 676;

game::game()
{
	// Initialize player
	if (!playerTexture.loadFromFile("spritesheet.png")) {
		// Handle loading failure
		std::cerr << "Failed to load spritesheet.png" << std::endl;
		// Return or throw an exception depending on your error handling strategy
	}
	player.sp(playerTexture);
	player.rect.left = 315;
	player.rect.top = 650;

	// Initialize maze
	if (!maze.loadMapTexture("map.png")) {
		// Handle loading failure
		std::cerr << "Failed to load map.png" << std::endl;
		// Return or throw an exception depending on your error handling strategy
	}

	// Initialize points
	if (!sPo.loadFromFile("big-1.png")) {
		// Handle loading failure
		std::cerr << "Failed to load big-1.png" << std::endl;
		// Return or throw an exception depending on your error handling strategy
	}
	if (!bPo.loadFromFile("big-0.png")) {
		// Handle loading failure
		std::cerr << "Failed to load big-0.png" << std::endl;
		// Return or throw an exception depending on your error handling strategy
	}
	points.resize(no_Coins);
	for (int i = 0; i < no_Coins; ++i) {
		points[i].setTexture(sPo);
	}
	maze.drawPoints(points, sPo);

	// Initialize blocks
	blocks.resize(no_Collisions);
	maze.mapCollision(blocks, blockMap);
}

void game::playerMovement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player.move_x = -2;
		player.move_y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player.move_x = 2;
		player.move_y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player.move_y = -2;
		player.move_x = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		player.move_y = 2;
		player.move_x = 0;
	}
	player.update();
}

void game::playerCollisions() {
	for (int i = 0; i < no_Collisions; ++i) {
		if (player.playerSprite.getGlobalBounds().intersects(blocks[i].getGlobalBounds())) {
			maze.drawCollision2(blocks[i], player, blockMap[i]);
		}
	}
}

void game::drawObjects(sf::RenderWindow& window) {
	window.clear();
	window.draw(maze.background);
	window.draw(player.playerSprite);
	for (int i = 0; i < no_Coins; ++i) {
		window.draw(points[i]);
		if (player.playerSprite.getGlobalBounds().intersects(points[i].getGlobalBounds())) {
			points[i].setScale(0, 0);
		}
	}
	for (int i = 0; i < no_Collisions; ++i) {
		window.draw(blocks[i]);
	}
	window.display();
}

int game:: level1(RenderWindow& window)
{

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		//// display position in the console
		//if (Mouse::isButtonPressed(Mouse::Left)) {
		//	Vector2i pos = Mouse::getPosition(window);
		//	cout << pos.x << " " << pos.y << endl;
		//}

		// player movment
		playerMovement();

		// player collision with blockes
		playerCollisions();

		// drawing objects
		drawObjects(window);
	}
	return 7;
}