#pragma once
#include <SFML\Graphics.hpp>
#include <sstream> 
using namespace sf;
class Mainmenu
{
public:

	Mainmenu();
	~Mainmenu();
	void Draw(RenderWindow& window);
private:
	RectangleShape mainmenuBG;
	Font gameFont;
	RectangleShape menuBGtextNG;
	Text menuTextNewGame;
	RectangleShape menuBGtextLS;
	Text menuTextLoadSave;
	RectangleShape menuBGtextC;
	Text menuTextCharacter;
	RectangleShape menuBGtextE;
	Text menuTextExit;
};

