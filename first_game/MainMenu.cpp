#include "MainMenu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;

//seting the constructor and the details of every member in the mainmenu class//
MainMenu::MainMenu(int width, int height) :score(0), width(width), height(height), selectedlevel(0)
{   

	Mainmenupic.loadFromFile("hopefully.jpg");
	background.setTexture(Mainmenupic);
	font.loadFromFile("font.otf");
	// herer we initialize the values of each membre in the class //

	menuchoice[0].setFont(font);
	menuchoice[0].setFillColor(Color{255,204,0});
	menuchoice[0].setString("Start");
	menuchoice[0].setCharacterSize(55);

	menuchoice[0].setPosition(Vector2f(width /4 -190, height / 4 -10));

	menuchoice[1].setFont(font);
	menuchoice[1].setFillColor(Color{ 255,255,255 });
	menuchoice[1].setString("leaderboard");
	menuchoice[1].setCharacterSize(55);
	menuchoice[1].setPosition(Vector2f(width / 4 - 255, height / 4 + 110));

	menuchoice[2].setFont(font);
	menuchoice[2].setFillColor(Color{ 255,255,255 });
	menuchoice[2].setString("options");
	menuchoice[2].setCharacterSize(55);
	menuchoice[2].setPosition(Vector2f(width / 4 - 210, height / 4 + 230));

	menuchoice[3].setFont(font);
	menuchoice[3].setFillColor(Color{ 255,255,255 });
	menuchoice[3].setString("Exit");
	menuchoice[3].setCharacterSize(55);
	menuchoice[3].setPosition(Vector2f(width / 4 - 190, height / 4 + 350));

	selected = 0;
}

MainMenu::~MainMenu() {}; // the destructor //

// the function to determine what choice the user is now slecting if he pressed enter in  the mainmenu //
void MainMenu::setselected(int n) 
{
	selected = n;
}

// the function to draw eact choice on the mainmenu window //
void MainMenu::draw(RenderWindow& window)
{
	for (int i = 0; i <= 3; i++) 
	{
		window.draw(menuchoice[i]);
	}
}

// updates the selected choice if the user moves down //
void MainMenu::movedown(int size, Text arr[])
{
	if (selected + 1 <= size)  // if the selected isn't the "exit" choice //
	{
		arr[selected].setFillColor(Color{ 255,255,255});
		selected++;
	}

	if (selected == size)  // to change the selected from "exit" to "start" // 
	{
		selected = 0;
	}

	arr[selected].setFillColor(Color{ 255,204,0 }); // changes the color of the new choice //
}

// updates the selected choice if the user moves up //
void MainMenu::moveup(int size, Text arr[])
{

	if (selected - 1 >= -1)  // if the selected isn't the "start" choice //
	{
		arr[selected].setFillColor(Color{ 255,255,255 });
		selected--;
	}

	if (selected == -1)  // to change the selected from "start" to "exit" // 
	{
		selected = size -1;
	}

	arr[selected].setFillColor(Color{ 255,204,0 }); // changes the color of the new choice //
}

//allow the player to choose the level or the difficulty//
int MainMenu::levelselection(RenderWindow& window)
{
	selected = 0 ;

	Texture background;
	background.loadFromFile("backedited.jpg");
	Sprite bg;
	bg.setTexture(background);

	Font font;
	font.loadFromFile("font.otf");

	Text levelt[4];

	levelt[0].setFont(font);
	levelt[0].setFillColor(Color{ 255,204,0 });
	levelt[0].setString("Level 1 - Difficulty : Easy");
	levelt[0].setCharacterSize(40);
	levelt[0].setPosition(Vector2f(width / 2 - 300, height / 2 - 100));

	levelt[1].setFont(font);
	levelt[1].setFillColor(Color{ 255,255,255 });
	levelt[1].setString("Level 2 - Difficulty : Meduim ");
	levelt[1].setCharacterSize(40);
	levelt[1].setPosition(Vector2f(width / 2 -300, height / 2 ));

	levelt[2].setFont(font);
	levelt[2].setFillColor(Color{ 255,255,255 });
	levelt[2].setString("Level 3 - Difficulty : Hard");
	levelt[2].setCharacterSize(40);
	levelt[2].setPosition(Vector2f(width / 2 - 300, height / 2 + 100));

	levelt[3].setFont(font);
	levelt[3].setFillColor(Color{ 255,255,255 });
	levelt[3].setString("CHoose the Difficulty :");
	levelt[3].setCharacterSize(55);
	levelt[3].setPosition(Vector2f(width / 2-220, height / 2-200));

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed())
			{
				window.close();
				return -1;
				break;
			}
			if (event.type == Event::KeyPressed) // checks the movements when the user preesses any button //
			{
				if (event.key.code == Keyboard::Up)
				{
					moveup(3,levelt);
				}
				if (event.key.code == Keyboard::Down)
				{
					movedown(3,levelt);
				}
				if (event.key.code == Keyboard::Return)
				{
					if (pressed() == 0)
					{
						return 6;
					}
					if (pressed() == 1)
					{
						return 7;
					}
					if (pressed() == 2)
					{
						return 8 ;
					}
				}
				if (event.key.code == Keyboard::Escape)
				{
					return 2 ;
				}
			}
		}
		window.clear();
		window.draw(bg);
		for (int i = 0; i <= 3; i++) 
		{
			window.draw(levelt[i]);
		}
		window.display();
	}
}

// the function opens a window to allow the player to leave his name //
int MainMenu::playername(RenderWindow& window, string &username)
{
	if (!username.empty())  // to check that the name field is clear or not //
	{
		username.clear();
	}

	Texture background;
	background.loadFromFile("backedited.jpg");
	Sprite bg;
	bg.setTexture(background);

	Font font;
	font.loadFromFile("font.otf");

	Text t1, t2;

	t1.setFont(font);
	t1.setFillColor(Color{ 255,255,255 });
	t1.setString("Enter your name :");
	t1.setCharacterSize(55);
	t1.setPosition(Vector2f(width / 2-200, height / 2-200));
	
	t2.setFillColor(Color{ 255,255,255 });
	t2.setCharacterSize(40);
	t2.setPosition(Vector2f(width / 2-150, height / 2-50));
	t2.setFont(font);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed())
			{
				window.close();
				return -1;
				break;
			}
			// to transfer the entered text to char and make it possible to converted in the string //
			if (event.type == Event::TextEntered && !Keyboard::isKeyPressed(Keyboard::Enter) && !Keyboard::isKeyPressed(Keyboard::Escape))
			{
				username += static_cast<char>(event.text.unicode);
			}
			// if backspace was pressed then reduce the size by 1 and remobe the last letter entered//
			if (Keyboard::isKeyPressed(Keyboard::BackSpace) && username.size() > 0) 
			{
				username.resize(username.size()-1);      
			}
			// If the name was valid and the enter was preesed will proceed to level selection
			if (Keyboard::isKeyPressed(Keyboard::Enter) && username.size() > 1)
			{
				return 5 ;
			}
			// when the escape button is pressed it would then return to the window before ie( the mainmenu) //
			if (Keyboard::isKeyPressed(Keyboard:: Escape)) 
			{
				return 1 ; 
			}
		}
		t2.setString(username);
		window.clear();
		window.draw(bg);
		window.draw(t1);
		window.draw(t2);
		window.display();
	}
}

// to start the mainmenu //
int MainMenu::gamemainmenu(RenderWindow& window)
{
	selected = 0;

	while (true)
	{
		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed) // to close the game window when the clpse button is pressed //
				{
					window.close();
					return -1;
					break;
				}
				if (event.type == Event::KeyPressed) // checks the movements when the user preesses any button //
				{
					if (event.key.code == Keyboard::Up)
					{
						moveup(4, menuchoice);
					}
					if (event.key.code == Keyboard::Down)
					{
						movedown(4, menuchoice);
					}
					if (event.key.code == Keyboard::Return)
					{
						if (pressed() == 0)
						{
							return 2;
						}
						if (pressed() == 1)
						{
							return 3;
						}
						if (pressed() == 2)
						{
							return 4;
						}
						if (pressed() == 3)
						{
							return -1;
						}
					}
				}
				window.clear();
				window.draw(background);
				draw(window);
				window.display();
			}
		}
	}

}