#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class HowToPlay
{
public:
	HowToPlay();
	~HowToPlay();

	void Run();
	void Draw(RenderWindow& window);
	bool GetActive() { return Active; };
	int GetforChangeWindow() { return forChangeWindow; };
private:
	bool Active = false;
	int forChangeWindow = 40;

	Font gameFont;

	RectangleShape howToPlayBG;
	Texture howToPlayTexture;

	Text returnToMenuText;
	RectangleShape returnToMenuBG;

	Event evnt;

	Vector2i mousePos;
	Vector2f mousePosF;
};

