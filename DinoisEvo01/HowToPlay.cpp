#include "HowToPlay.h"

HowToPlay::HowToPlay()
{
	gameFont.loadFromFile("PixelEmulator-xq08.ttf");

	howToPlayTexture.loadFromFile("BGforHowToPlay.png");
	howToPlayBG.setTexture(&howToPlayTexture);
	howToPlayBG.setSize(Vector2f(1000, 700));
	howToPlayBG.setPosition(0, 0);

	returnToMenuBG.setSize(Vector2f(300, 50));
	returnToMenuBG.setPosition(Vector2f(650, 570));

	returnToMenuText.setFont(gameFont);
	returnToMenuText.setOutlineColor(Color::Black);
	returnToMenuText.setOutlineThickness(2);
	returnToMenuText.setFillColor(Color::White);
	returnToMenuText.setStyle(Text::Regular);
	returnToMenuText.setString("Return To Menu");
	returnToMenuText.setCharacterSize(25);
	returnToMenuText.setOrigin(Vector2f(75, 25));
	returnToMenuText.setPosition(Vector2f(750, 600));
}

HowToPlay::~HowToPlay()
{
}

void HowToPlay::Run()
{
	Active = true;
	forChangeWindow = 40;
	//MainMenu//
	if (this->returnToMenuBG.getGlobalBounds().contains(mousePosF))
	{
		returnToMenuText.setOutlineColor(Color::Black);
		returnToMenuText.setFillColor(Color::Red);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			forChangeWindow = 99;
			Active = false;
		}
	}
	else {
		returnToMenuText.setOutlineColor(Color::Black);
		returnToMenuText.setFillColor(Color::White);
	}
}

void HowToPlay::Draw(RenderWindow& window)
{
	mousePos = Mouse::getPosition(window);
	Vector2f mousePos_F(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	mousePosF = mousePos_F;
	window.draw(howToPlayBG);
	window.draw(returnToMenuText);
}
