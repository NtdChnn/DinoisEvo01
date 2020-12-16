#include "EnterName.h"

EnterName::EnterName(Font font):
	textbox (30, Color::Black, &font, Vector2f(500,350), true, true, 15)
{
	EnterNameTexture.loadFromFile("BGforEnterName.png");
	EnterNameBG.setTexture(&EnterNameTexture);
	EnterNameBG.setPosition(0, 0);
	EnterNameBG.setSize(Vector2f(1000, 700));

	returnToMenuBG.setSize(Vector2f(300, 50));
	returnToMenuBG.setPosition(Vector2f(650, 570));

	returnToMenuText.setFont(font);
	returnToMenuText.setOutlineColor(Color::Black);
	returnToMenuText.setOutlineThickness(2);
	returnToMenuText.setFillColor(Color::White);
	returnToMenuText.setStyle(Text::Regular);
	returnToMenuText.setString("Return To Menu");
	returnToMenuText.setCharacterSize(25);
	returnToMenuText.setOrigin(Vector2f(75, 25));
	returnToMenuText.setPosition(Vector2f(750, 600));
}

EnterName::~EnterName()
{
}

void EnterName::Draw(RenderWindow& window)
{
	mousePos = Mouse::getPosition(window);
	Vector2f mousePos_F(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	mousePosF = mousePos_F;
	window.draw(EnterNameBG);
	textbox.draw(window);
}

void EnterName::Run(RenderWindow& window)
{
	Active = true;
	forChangeWindow = 50;
	Event evnt;
	while (window.pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case Event::TextEntered:
			textbox.update(evnt);
			break;
		case Event::KeyPressed:
			if (evnt.key.code == Keyboard::Enter)
			{
				collectHS = false;
				name = textbox.getInput();
				cout << name;
				textbox.setSelected(false);
				forChangeWindow = 0;
				Active = false;
			}
			break;
		}
	}

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
