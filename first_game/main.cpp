#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "MainMenu.h"
#include "player.h"
#include "maze.h"
#include "game.h"


using namespace std;
using namespace sf;

const int noCollisions = 150;
const int noCoins = 676;


int main() {
	game game;
	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(desktopMode.width - 250, desktopMode.height - 70), "SFML works!");
	window.setFramerateLimit(60);
	MainMenu MainMenu(static_cast<float>(desktopMode.width), static_cast<float>(desktopMode.height));
	int current_phase = 1; // variable to determine the cuurent page the user is on //
	while (window.isOpen())
	{
		if (current_phase == 1)
		{
			current_phase = MainMenu.gamemainmenu(window);
		}
		if (current_phase == 2)
		{
			current_phase = MainMenu.playername(window, MainMenu.pname);
		}
		if (current_phase == 3)
		{

		}
		if (current_phase == 4)
		{

		}
		if (current_phase == 5)
		{
			current_phase = MainMenu.levelselection(window);
		}
		if (current_phase == 6)
		{
			
			current_phase = game.level1(window,MainMenu.score);
		}
		/*if (current_phase == 7)
		{
			current_phase = level2;
		}
		if (current_phase == 8)
		{
			current_phase = level3;
		}*/
		if (current_phase == -1)
		{
			window.close();
			break;
		}
	}
	return 0;
}


