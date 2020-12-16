#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class LeaderBoard
{
public:
	LeaderBoard();
	~LeaderBoard();

	void Draw(RenderWindow& window);
	void Run();
	int GetforChangeWindow() { return forChangeWindow; };
	bool GetActive() { return Active; };
private:
	RectangleShape LeaderBoardBG;
	Texture LeaderBoardTexture;

	FILE* file;
	char temp[25] = {};
	string nameArr[6];
	int scoreArr[6] = {};

	Event evnt;

	Text returnToMenuText;
	RectangleShape returnToMenuBG;

	Font gameFont;

	Vector2i mousePos;
	Vector2f mousePosF;

	Text text[10];

	bool Active = false;
	int forChangeWindow = 0;
};

