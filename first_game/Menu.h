#include <iostream>
#include <SFML/Graphics.hpp>

#pragma once
using namespace std;
using namespace sf;
class Menu
{
public:
	int selected;
	Font font;
	Text mainMenuText[3];
	Menu(unsigned int width, unsigned int height);
	void drawMenuText(RenderWindow& window);
	void Move_up();
	void Move_down();
	void set_selected(int n);
	int pressed();
	~Menu();
};
