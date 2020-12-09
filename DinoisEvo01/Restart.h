#pragma once
#include <SFML\Graphics.hpp>
#include <windows.h>
using namespace sf;
class Restart
{
public:
	Restart();
	~Restart();

	void Check( bool gameOver);
	bool restartStatus() { return restart; };
private:
	bool restart = false;
	int checkpress01 = 0;
	int checkpress02 = 0;
};

