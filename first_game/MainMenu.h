#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std; 
using namespace sf;

class MainMenu
{
public :
	int selectedlevel;
	string pname;
	int height, width;
	Text menuchoice[4];
	Texture Mainmenupic;
	Sprite background;


	MainMenu(float width, float height);  //constructor//

	void draw(RenderWindow& window);
	void moveup(int textnumber, Text arr[]);
	void movedown(int textnumber, Text arr[]);
	void setselected(int a); 

	// a function that returns the selected option when the "enter"key is pressed //
	int pressed() 
	{
		return selected;
	}   // a function that returns the selected option when the "enter"key is pressed //

	int levelselection(RenderWindow& window);
	int playername(RenderWindow& windwow, string &palyername);
	int gamemainmenu(RenderWindow& window );


	~MainMenu(); // destructor//

private :
	int selected;
	Font font;
};

