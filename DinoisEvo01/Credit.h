#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class Credit
{
public:
	Credit();
	~Credit();

	void Draw(RenderWindow& window);
	void Run();
	bool GetActive() { return Active; };
	int GetforChangeWindow() { return forChangeWindow; };
private:
	bool Active = false;
	int forChangeWindow = 40;

	Font gameFont;

	RectangleShape howToPlayBG;
	Texture howToPlayTexture;

	Event evnt;

	Text returnToMenuText;
	RectangleShape returnToMenuBG;

	Vector2i mousePos;
	Vector2f mousePosF;
};

