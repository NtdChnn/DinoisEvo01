#include "Pause.h"

Pause::Pause()
{
	gameFont.loadFromFile("PixelEmulator-xq08.ttf");

	pauseText01.setFont(gameFont);
	pauseText01.setFillColor(Color::White);
	pauseText01.setStyle(Text::Regular);
	pauseText01.setString("PAUSE");
	pauseText01.setCharacterSize(100);

	pauseText02.setFont(gameFont);
	pauseText02.setFillColor(Color::White);
	pauseText02.setStyle(Text::Regular);
	pauseText02.setString("Press 'P' to continue");
	pauseText02.setCharacterSize(50);

	Color pauseColor(0, 0, 0, 100);
	pauseBG.setFillColor(pauseColor);
	pauseBG.setSize(Vector2f(1000, 700));
	intPause = 0;
	checkpress01 = 0;
	checkpress02 = 0;
}

Pause::~Pause()
{
}

void Pause::checkPause()
{
	printf("%d", intPause);
	if (Keyboard::isKeyPressed(Keyboard::Key::P) && run == true)
	{
		checkpress02 = checkpress01;
		checkpress01 = 1;
	}
	else { checkpress01 = 0; checkpress02 = checkpress01;}
	
	if (checkpress01 != checkpress02)
	{
		if (intPause == 1)
		{
			intPause = 0;
			Sleep(100);
		}
		else if (intPause == 0)
		{
			intPause = 1;
			Sleep(100);
		}
	}
}

void Pause::GetPlayerPosition(Vector2f(position))
{
	pauseBG.setPosition(position.x - 500, 0);
	pauseText01.setPosition(position.x - 325, 200);
	pauseText02.setPosition(position.x - 325, 300);
}

void Pause::Setrun(bool run)
{
	this->run = run;
}

void Pause::Draw(RenderWindow& window)
{
	if (intPause == 1)
	{
		window.draw(pauseBG);
		window.draw(pauseText01);
		window.draw(pauseText02);
	}
}


