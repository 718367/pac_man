
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
}

void game::gamePlayPage(RenderWindow& window)
{
	Texture tx;
	tx.loadFromFile("spritesheet.png");
	Player player;
	player.sp(tx);
	player.rect.left = 315;
	player.rect.top = 650;

	maze maze_map;
	maze_map.loadMapTexture("map.png");

	Texture sPo, bPo;
	sPo.loadFromFile("big-1.png");
	bPo.loadFromFile("big-0.png");
	Sprite* points = new Sprite[no_Coins];

	RectangleShape* blocks = new RectangleShape[no_Collisions];
	map<int, char> blockMap;
	maze_map.mapCollision(blocks, blockMap);
	maze_map.drawPoints(points, sPo);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		if (Mouse::isButtonPressed(Mouse::Left)) {
			Vector2i pos = Mouse::getPosition(window);
			cout << pos.x << " " << pos.y << endl;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
			player.move_x = -2;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
			player.move_x = 2;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
			player.move_y = -2;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
			player.move_y = 2;
		}

		player.update();

		for (int i = 0; i < no_Collisions; i++) {
			if (player.playerSprite.getGlobalBounds().intersects(blocks[i].getGlobalBounds())) {
				maze_map.drawCollision2(blocks[i], player, blockMap[i]);
			}
		}

		window.clear();
		window.draw(maze_map.background);
		window.draw(player.playerSprite);
		for (int i = 0; i < no_Coins; i++)
		{
			window.draw(points[i]);
			if (player.playerSprite.getGlobalBounds().intersects(points[i].getGlobalBounds())) {
				points[i].setScale(0, 0);
			}
		}
		for (int i = 0; i < no_Collisions; i++)
		{
			window.draw(blocks[i]);
		}
		window.display();
	}
}

