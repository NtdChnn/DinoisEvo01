#pragma once
#include <SFML\Graphics.hpp>
#include <sstream> 
using namespace sf;
class Mainmenu
{
public:

	Mainmenu();
	~Mainmenu();

	void Run();
	void Draw(RenderWindow& window);
	void Updatemousepos(RenderWindow& window);
	int GetChangeWindow() { return forChangeWindow; };

private:
	RectangleShape mainmenuBG;
	Texture BGtexture;

	int forChangeWindow = 0;

	Font gameFont;

	RectangleShape menuBGtextNG;
	Texture NGTexture;
	Text menuTextNewGame;

	RectangleShape menuBGtextLDB;
	Texture LDBTexture;
	Text menuTextLeaderBoard;

	RectangleShape menuBGtextS;
	Texture STexture;
	Text menuTextStage;

	RectangleShape menuBGtextE;
	Texture ETexture;
	Text menuTextExit;
	int exit = 0;

	Vector2i mousePos;
	Vector2f mousePosF;
};

