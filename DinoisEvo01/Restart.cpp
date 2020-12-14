#include "Restart.h"

Restart::Restart()
{
}

Restart::~Restart()
{
}

void Restart::CheckGameOver(bool gameOver)
{
	if (Keyboard::isKeyPressed(Keyboard::Key::R) && gameOver == true)
	{
		checkpress02 = checkpress01;
		checkpress01 = 1;
	}
	else { checkpress01 = 0; checkpress02 = checkpress01; }



	if (checkpress01 != checkpress02)
	{
		restart = true;
	}
	else restart = false;
}

void Restart::Check(bool RESERPLZ)
{
	if (RESERPLZ == true)
	{
		restart = true;
	}
	else restart = false;
}

