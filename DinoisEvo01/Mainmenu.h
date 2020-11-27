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
	Texture BGtexture;

	Font gameFont;

	RectangleShape menuBGtextNG;
	Texture NGTexture;
	Text menuTextNewGame;

	RectangleShape menuBGtextLS;
	Texture LSTexture;
	Text menuTextLoadSave;

	RectangleShape menuBGtextC;
	Texture CTexture;
	Text menuTextCharacter;

	RectangleShape menuBGtextE;
	Texture ETexture;
	Text menuTextExit;
};

