#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>
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
		cout << "Failed to load spritesheet.png" << std::endl;
	}
	player.sp(playerTexture);
	player.rect.left = 315;
	player.rect.top = 650-10;

	// Initialize maze
	if (!maze.loadMapTexture("map.png")) {
		cout << "Failed to load map.png" << std::endl;
	}

	// Initialize points
	if (!sPo.loadFromFile("big-1.png")) {
		cout << "Failed to load big-1.png" << std::endl;
	}
	if (!bPo.loadFromFile("big-0.png")) {
		cout << "Failed to load big-0.png" << std::endl;
	}
	points.resize(no_Coins);
	for (int i = 0; i < no_Coins; ++i) {
		points[i].setTexture(sPo);
	}
	maze.drawPoints(points, sPo);

	// Initialize blocks
	blocks.resize(no_Collisions);
	maze.mapCollision(blocks, blockMap);
	// Initialize  score
	if (!font.loadFromFile("font.otf")) {
		cout << "Failed to load font.otf" << std::endl;
	}
	scoreText.setFont(font);
	scoreText.setString("Score :");
	scoreText.setCharacterSize(55);
	scoreText.setFillColor(sf::Color::Yellow);
	scoreText.setPosition(700, 150);

	level.setFont(font);
	level.setCharacterSize(80);
	level.setFillColor(sf::Color::White);
	level.setPosition(710, 30);
}

void game::playerMovement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player.move_x = -4;
		player.move_y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player.move_x = 4;
		player.move_y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player.move_y = -4;
		player.move_x = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		player.move_y = 4;
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



void game::drawObjects(sf::RenderWindow& window, int& s) {
	window.clear();
	window.draw(scoreText);
	window.draw(level);
	window.draw(maze.background);
	window.draw(player.playerSprite);
	for (int i = 0; i < no_Coins; ++i) {
		window.draw(points[i]);
		if (player.playerSprite.getGlobalBounds().intersects(points[i].getGlobalBounds())) {
			points[i].setScale(0, 0);
			s += 10;
		}
	}
	for (int i = 0; i < no_Collisions; ++i) {
		window.draw(blocks[i]);
	}
	window.display();
}

int game::level1(RenderWindow& window, int& score)
{
	level.setString("Level 1 - Easy");
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

		scoreText.setString("Score: " + std::to_string(score));


		// player movment
		playerMovement();

		// player collision with blockes
		playerCollisions();

		// drawing objects
		drawObjects(window,score);
	}
	return 7;
}