#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>
#include "player.h"
#include "maze.h"
float collisionThinkness = 2.0f;


bool maze::loadMapTexture(const std::string& filename) {
	if (!texture.loadFromFile(filename)) {
		std::cerr << "Failed to load map texture" << std::endl;
		return false;
	}
	background.setTexture(texture);
	background.setScale(1.5f, 1.4f);
	return true;
}

void maze::drawPoints(vector<sf::Sprite>& points, sf::Texture& point) {
	const int rowWidth = 26; // Width of each row in the maze
	const int section1End = 312;
	const int section2End = 442;
	const int section3End = 546;
	const int section4End = 572;

	int xIndex = 0;
	int yIndex = 0;
	int pointIndex = 0;

	// Loop through each point
	for (int i = 0; i < noCoins; i++) {
		// Check if xIndex exceeds row width
		if (xIndex == rowWidth) {
			xIndex = 0;
			yIndex++;
		}

		// Check if point should be drawn based on maze layout
		if (isEmptyPlace(xIndex, yIndex)) {
			// Calculate position of the point
			int xpos = xIndex * 24 + 25;
			int ypos = 0;

			// Determine ypos based on pointIndex range
			if (i < section1End)
				ypos = yIndex * 23 + 25;
			else if (i >= section1End && i < section2End)
				ypos = yIndex * 24 + 27;
			else if (i >= section2End && i < section3End)
				ypos = yIndex * 23 + 60;
			else if (i >= section3End && i < section4End)
				ypos = yIndex * 23 + 70;
			else
				ypos = yIndex * 23 + 78;

			// Set texture and position of the point
			points[i].setTexture(point);
			points[i].setPosition(float(xpos), float(ypos));

			// Increment pointIndex
			pointIndex++;
		}

		// Increment xIndex
		xIndex++;
	}
}


void maze::drawCollision(sf::RectangleShape& block, float X, float Y, float X_position, float Y_position) {
	block.setSize(Vector2f(X, Y));
	block.setPosition(X_position, Y_position);
}

void maze::drawCollision2(sf::RectangleShape block, Player& player, char dr)
{
	if (block.getSize().x == collisionThinkness) {
		if (dr == 'r')
			player.rect.left = block.getPosition().x - 39;

		else if (dr == 'l')
			player.rect.left = block.getPosition().x + 5;
		player.move_x = 0;
		player.playerSprite.setTextureRect(sf::IntRect(0, 0, 26, 26));
	}
	else if (block.getSize().y == collisionThinkness) {
		if (dr == 'r')
			player.rect.top = block.getPosition().y - 39;
		else if (dr == 'l')
			player.rect.top = block.getPosition().y + 5;
		player.move_y = 0;
		player.playerSprite.setTextureRect(sf::IntRect(0, 0, 26, 26));
	}
}

void maze::mapCollision(vector<sf::RectangleShape>& blocks, std::map<int, char>& map) {

	std::ifstream fileIn("mapCollisions.txt");

	int index = 0;
	float size_x, size_y, position_x, position_y;
	char direction;

	for (int i = 0; i < 143; i++)
	{
		fileIn >> size_x >> size_y >> position_x >> position_y >> direction;
		drawCollision(blocks[i], size_x, size_y, position_x, position_y);
		map[i] = direction;
	}


	fileIn.close();
}


bool maze::isEmptyPlace(int xIndex, int yIndex) {
	if (xIndex == 12 || xIndex == 13) {
		if (yIndex != 4 && yIndex != 10) {
			return false;
		}
		else
			return true;
	}
	if (yIndex == 1 || yIndex == 2 || yIndex == 3) {
		if (xIndex != 5 && xIndex != 11 && xIndex != 12 && xIndex != 13 && xIndex != 14 && xIndex != 20 && xIndex != 25 && xIndex != 0)
			return false;
		else
			return true;
	}
	if (yIndex == 5 || yIndex == 6) {
		if (xIndex != 5 && xIndex != 8 && xIndex != 17 && xIndex != 20 && xIndex != 25 && xIndex != 0)
			return false;
		else
			return true;

	}if (yIndex == 7) {
		if (xIndex == 6 || xIndex == 7 || xIndex == 18 || xIndex == 19)
			return false;
		else
			return true;
	}
	if (yIndex == 8 || yIndex == 9) {
		if (xIndex != 5 && xIndex != 11 && xIndex != 14 && xIndex != 20)
			return false;
		else
			return true;
	}if (yIndex == 10) {
		if (xIndex == 0 || xIndex == 1 || xIndex == 2 || xIndex == 3 || xIndex == 4 || xIndex == 6 || xIndex == 7 || xIndex == 18 || xIndex == 19 || xIndex == 21 || xIndex == 22 || xIndex == 23 || xIndex == 24 || xIndex == 25)
			return false;
		else
			return true;
	}if (yIndex == 11) {
		if (xIndex != 5 && xIndex != 8 && xIndex != 17 && xIndex != 20)
			return false;
		else
			return true;
	}if (yIndex == 12) {
		if (xIndex != 9 && xIndex != 10 && xIndex != 11 && xIndex != 14 && xIndex != 15 && xIndex != 16)
			return true;
		else
			return false;
	}if (yIndex == 13 || yIndex == 14 || yIndex == 16) {
		if (xIndex != 5 && xIndex != 8 && xIndex != 17 && xIndex != 20)
			return false;
		else
			return true;
	}if (yIndex == 15) {
		if (xIndex != 5 && xIndex != 8 && xIndex != 9 && xIndex != 10 && xIndex != 11 && xIndex != 14 && xIndex != 15 && xIndex != 16 && xIndex != 17 && xIndex != 20)
			return false;
		else
			return true;
	}if (yIndex == 18 || yIndex == 19) {
		if (xIndex != 0 && xIndex != 5 && xIndex != 11 && xIndex != 14 && xIndex != 20 && xIndex != 25)
			return false;
		else
			return true;
	}if (yIndex == 20) {
		if (xIndex != 3 && xIndex != 4 && xIndex != 21 && xIndex != 22)
			return true;
		else
			return false;
	}if (yIndex == 21) {
		if (xIndex != 2 && xIndex != 5 && xIndex != 8 && xIndex != 23 && xIndex != 20 && xIndex != 17)
			return false;
		else
			return true;
	}if (yIndex == 22) {
		if (xIndex != 6 && xIndex != 7 && xIndex != 18 && xIndex != 19)
			return true;
		else
			return false;
	}if (yIndex == 23 || yIndex == 24) {
		if (xIndex != 0 && xIndex != 11 && xIndex != 14 && xIndex != 25)
			return false;
		else
			return true;
	}
}

void maze::draw(sf::RenderWindow& window) {
	window.draw(background);
	for (int i = 0; i < noCollisions; i++) {
		window.draw(blocks[i]);
	}
}



