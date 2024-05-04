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
	game game;
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
			game.gamePlayPage(window);
		}
	}

	return 0;
}


