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
private:
	int intPause;
	int checkpress01;
	int checkpress02;
	Text pauseText01;
	Text pauseText02;
	Font gameFont;
	RectangleShape pauseBG;
};

