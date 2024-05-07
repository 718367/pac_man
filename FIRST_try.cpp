#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "MainMenu.h"

using namespace std ;
using namespace sf ;



int main()
{
	RenderWindow window(VideoMode(3000, 2000), "PacMan", Style::Default);
	MainMenu MainMenu(3000, 2000);
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
		/*if (current_phase == 6)
		{
			current_phase = level1;
		}
		if (current_phase == 7)
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
}