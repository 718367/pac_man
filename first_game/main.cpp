 #include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <map>
#include <iterator>
#include "player.h"
#include "maze.h"
#include <fstream>
#include <sstream>

using namespace std;
using namespace sf;

const int noCollisions = 150;
const int noCoins = 676;
int pagenum = -1;

/*
	< page route >
	-1  :: menu page
	0   :: gameplay page
	1   :: instrections page
	2   :: exit
*/

void gamePlayPage(RenderWindow& window);
int main() {
	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktopMode, "SFML works!");
	Menu menu(desktopMode.width, desktopMode.height);
	window.setFramerateLimit(60);

	while (true) {
		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed) {
					window.close();
					break;
				}
				if (event.type == Event::KeyPressed) {
					if (event.key.code == Keyboard::Up) {
						menu.Move_up();
					}
					if (event.key.code == Keyboard::Down) {
						menu.Move_down();
					}
					if (event.key.code == Keyboard::Return) {
						if (menu.pressed() == 0) {
							pagenum = 0;
						}
						if (menu.pressed() == 1) {
							pagenum = 1;
						}
						if (menu.pressed() == 2) {
							pagenum = 2;
						}
					}
				}
			}
			window.clear();
			if (pagenum != -1) {
				break;
			}
			menu.draw(window);
			window.display();
		}
		if (pagenum == 2) {
			window.close();
		}
		if (pagenum == 0) {
			gamePlayPage(window);
		}
	}

	return 0;
}
void gamePlayPage(RenderWindow& window) {
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
	Sprite* points = new Sprite[noCoins];



	RectangleShape blocks[noCollisions];
	map<int, char> blockMap;
	maze_map.mapCollision(blocks, blockMap);
	maze_map.drawPoints(points, sPo);

	while (window.isOpen()) {
		Event event;
		/*
			float timer = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		timer /= 650;
		if (timer > 20) {
			timer = 20;
		}
		*/

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		if (Mouse::isButtonPressed(Mouse::Left)) {
			Vector2i pos = Mouse::getPosition(window);
			cout << pos.x << " " << pos.y << endl;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
			player.move_x = -4;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
			player.move_x = 4;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
			player.move_y = -4;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
			player.move_y = 4;
		}

		player.update();

		for (int i = 0; i < noCollisions; i++) {
			if (player.playerSprite.getGlobalBounds().intersects(blocks[i].getGlobalBounds())) {
				maze_map.drawCollision2(blocks[i], player, blockMap[i]);
			}
		}

		window.clear();
		window.draw(maze_map.background);
		window.draw(player.playerSprite);
		for (int i = 0; i < noCoins; i++)
		{
			window.draw(points[i]);
			if (player.playerSprite.getGlobalBounds().intersects(points[i].getGlobalBounds())) {
				points[i].setScale(0, 0);
			}
		}
		/**/
		for (int i = 0; i < noCollisions; i++)
		{
			window.draw(blocks[i]);
		}


		window.display();
	}
}

