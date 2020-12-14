#pragma once
#include <SFML\Graphics.hpp>
#include <windows.h>
#include <sstream> 
using namespace sf;
class Pause
{
public:
	Pause();
	~Pause();

	void checkPause();
	int Getintpause() { return intPause; };
	void Draw(RenderWindow& window);
	void GetPlayerPosition(Vector2f(position));
	void Setrun(bool run);
	int GetForChangewindow();
	int GetCheckReturnToMenu() { return checkReturnToMenu; };
	void Updatemousepos(RenderWindow& window);

private:
	int intPause;
	int checkpress01;
	int checkpress02;
	bool run;
	Text pauseText01;
	Text pauseText02;
	Font gameFont;
	RectangleShape pauseBG;

	Text returnToMenuText;
	RectangleShape returnToMenuBG;
	int forChangeWindow;
	int checkReturnToMenu = 0;

	Vector2i mousePos;
	Vector2f mousePosF;
	Vector2f playerPosition;
};

