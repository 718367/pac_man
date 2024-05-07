#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>
#include "Menu.h"
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

void maze::drawPoints(sf::Sprite points[], sf::Texture& point) {
	for (int i = 0, xIndex = 0, yIndex = 0, xpos, ypos; i < noCoins; i++, xIndex++)
	{
		if (i < 312) {
			if (xIndex == 26) {
				xIndex = 0;
				yIndex++;
			}
			if (isEmptyPlace(xIndex, yIndex)) {
				xpos = xIndex * 24 + 25;
				ypos = yIndex * 23 + 25;
				points[i].setTexture(point);
				points[i].setPosition(float(xpos), float(ypos));
			}
		}
		else if (i >= 312 && i < 442) {
			if (xIndex == 26) {
				xIndex = 0;
				yIndex++;
			}
			if (isEmptyPlace(xIndex, yIndex)) {
				xpos = xIndex * 24 + 25;
				ypos = yIndex * 24 + 27;
				points[i].setTexture(point);
				points[i].setPosition(float(xpos), float(ypos));
			}
		}
		else if (i >= 442 && i < 546) {
			if (xIndex == 26) {
				xIndex = 0;
				yIndex++;
			}
			if (isEmptyPlace(xIndex, yIndex)) {
				xpos = xIndex * 24 + 25;
				ypos = yIndex * 23 + 60;
				points[i].setTexture(point);
				points[i].setPosition(float(xpos), float(ypos));
			}
		}
		else if (i >= 546 && i < 572) {
			if (xIndex == 26) {
				xIndex = 0;
				yIndex++;
			}
			if (isEmptyPlace(xIndex, yIndex)) {
				xpos = xIndex * 24 + 25;
				ypos = yIndex * 23 + 70;
				points[i].setTexture(point);
				points[i].setPosition(float(xpos), float(ypos));
			}
		}
		else {
			if (xIndex == 26) {
				xIndex = 0;
				yIndex++;
			}
			if (isEmptyPlace(xIndex, yIndex)) {
				xpos = xIndex * 24 + 25;
				ypos = yIndex * 23 + 78;
				points[i].setTexture(point);
				points[i].setPosition(float(xpos), float(ypos));
			}
		}

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
	}
	else if (block.getSize().y == collisionThinkness) {
		if (dr == 'r')
			player.rect.top = block.getPosition().y - 39;
		else if (dr == 'l')
			player.rect.top = block.getPosition().y + 5;
	}
}

void maze::mapCollision(sf::RectangleShape blocks[], std::map<int, char>& map) {

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
