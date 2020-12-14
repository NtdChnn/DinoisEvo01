#include "Pause.h"

Pause::Pause()
{
	gameFont.loadFromFile("PixelEmulator-xq08.ttf");

	pauseText01.setFont(gameFont);
	pauseText01.setOutlineColor(Color::Black);
	pauseText01.setOutlineThickness(5);
	pauseText01.setFillColor(Color::White);
	pauseText01.setStyle(Text::Regular);
	pauseText01.setString("PAUSE");
	pauseText01.setCharacterSize(100);

	pauseText02.setFont(gameFont);
	pauseText02.setOutlineColor(Color::Black);
	pauseText02.setOutlineThickness(3);
	pauseText02.setFillColor(Color::White);
	pauseText02.setStyle(Text::Regular);
	pauseText02.setString("Press 'P' to continue");
	pauseText02.setCharacterSize(50);

	returnToMenuText.setFont(gameFont);
	returnToMenuText.setOutlineColor(Color::Black);
	returnToMenuText.setOutlineThickness(2);
	returnToMenuText.setFillColor(Color::White);
	returnToMenuText.setStyle(Text::Regular);
	returnToMenuText.setString("Return To Menu");
	returnToMenuText.setCharacterSize(25);
	returnToMenuText.setOrigin(Vector2f(75, 25));

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

void Pause::GetPlayerPosition(Vector2f(position))
{
	this->playerPosition = position;
	pauseBG.setPosition(position.x - 500, 0);
	pauseText01.setPosition(position.x - 325, 200);
	pauseText02.setPosition(position.x - 325, 300);
	returnToMenuBG.setPosition(position.x + 300, 590);
	returnToMenuText.setPosition(Vector2f(position.x + 250, 600));
}


void Pause::checkPause()
{
	//CheckERROR//
	//printf("%d", intPause);
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

	if (mousePos.x >= 650 && mousePos.x <= 950 && mousePos.y <= 615 && mousePos.y >= 565 && intPause == 1)
	{
		returnToMenuText.setOutlineColor(Color::Black);
		Color Gray(125, 130, 122, 255);
		returnToMenuText.setFillColor(Gray);
		returnToMenuText.setCharacterSize(30);
		returnToMenuText.setPosition(returnToMenuText.getPosition().x-30, 600);
		printf("Collision\n");
		if (Mouse::isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Key::N))
		{
			//Checkerror//
			//printf("%d ",forChangeWindow);
			//printf("%d \n",checkReturnToMenu);
			checkReturnToMenu = 1;
			forChangeWindow = 99;
			intPause = 0;
		}
	} 
	else {
		returnToMenuText.setOutlineColor(Color::Black);
		returnToMenuText.setFillColor(Color::White);
		returnToMenuText.setCharacterSize(25);
		returnToMenuText.setPosition(playerPosition.x +250, 600);
		checkReturnToMenu = 0;
	}
}


void Pause::Setrun(bool run)
{
	this->run = run;
}

int Pause::GetForChangewindow()
{
	return forChangeWindow;
}

void Pause::Updatemousepos(RenderWindow& window)
{
	mousePos = Mouse::getPosition(window);
	Vector2f mousePos_F(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	mousePosF = mousePos_F;
}

void Pause::Draw(RenderWindow& window)
{
	if (intPause == 1)
	{
		window.draw(pauseBG);
		window.draw(pauseText01);
		window.draw(pauseText02);
		window.draw(returnToMenuText);
	}
}


