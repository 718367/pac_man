#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>
#include "Menu.h"
#include "player.h"
#include "maze.h"
using namespace std;
using namespace sf;

Menu::Menu(unsigned int width, unsigned int height) {
	font.loadFromFile("Gatrich-BF63dc6fcf996b7.otf");
	selected = 0;
	for (unsigned int i = 0; i < 3; i++)

	{
		mainMenuText[i].setPosition(Vector2f(25, i * 150 + 50));
		mainMenuText[i].setCharacterSize(60);
		mainMenuText[i].setFont(font);
		if (i == 0) {
			mainMenuText[i].setString("Play");
			if (selected == 0) {
				mainMenuText[i].setFillColor(Color{ 255,204,0 });
			}
			else {
				mainMenuText[i].setFillColor(Color::White);
			}
		}
		else if (i == 1) {
			mainMenuText[i].setString("Instructions");
			if (selected == 1) {
				mainMenuText[i].setFillColor(Color{ 255,204,0 });
			}
			else {
				mainMenuText[i].setFillColor(Color::White);
			}
		}
		else {
			mainMenuText[i].setString("Exit");
			if (selected == 2) {
				mainMenuText[i].setFillColor(Color{ 255,204,0 });
			}
			else {
				mainMenuText[i].setFillColor(Color::White);
			}
		}
	}

}

Menu::~Menu() {};

void Menu::set_selected(int n) {
	selected = n;
}

int Menu::pressed() {
	return selected;
}

void Menu::drawMenuText(RenderWindow& window) {
	for (int i = 0; i < 3; i++) {
		window.draw(Menu::mainMenuText[i]);
	}
}

void Menu::Move_down() {
	if (selected <= 2) {
		mainMenuText[selected].setFillColor(Color::White);
		selected++;
		if (selected > 2) {
			selected = 0;
		}
		mainMenuText[selected].setFillColor(Color{ 255,204,0 });
	}
}

void Menu::Move_up() {
	if (selected >= 0) {
		mainMenuText[selected].setFillColor(Color::White);
		selected--;
		if (selected < 0)
			selected = 2;
		mainMenuText[selected].setFillColor(Color{ 255,204,0 });
	}
}