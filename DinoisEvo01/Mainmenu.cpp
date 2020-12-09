#include "Mainmenu.h"

Mainmenu::Mainmenu()
{

	mainmenuBG.setSize(Vector2f(1000.0f, 700.0f));
	BGtexture.loadFromFile("BGforMenu.png");
	mainmenuBG.setTexture(&BGtexture);
	mainmenuBG.setOrigin(Vector2f(0.0f, 0.0f));
	mainmenuBG.setPosition(Vector2f(0.0f, 0.0f));

	menuBGtextNG.setSize(Vector2f(150.0f, 50.0f));
	NGTexture.loadFromFile("BGforMenuNG.png");
	menuBGtextNG.setTexture(&NGTexture);
	menuBGtextNG.setOrigin(Vector2f(50.0f, 25.0f));
	menuBGtextNG.setPosition(Vector2f(250.0f, 350.0f));

	menuBGtextLS.setSize(Vector2f(150.0f, 50.0f));
	LSTexture.loadFromFile("BGforMenuLS.png");
	menuBGtextLS.setTexture(&LSTexture);
	menuBGtextLS.setOrigin(Vector2f(50.0f, 25.0f));
	menuBGtextLS.setPosition(Vector2f(250.0f, 450.0f));

	menuBGtextC.setSize(Vector2f(150.0f, 50.0f));
	CTexture.loadFromFile("BGforMenuC.png");
	menuBGtextC.setTexture(&CTexture);
	menuBGtextC.setOrigin(Vector2f(50.0f, 25.0f));
	menuBGtextC.setPosition(Vector2f(750.0f, 350.0f));

	menuBGtextE.setSize(Vector2f(150.0f, 50.0f));
	ETexture.loadFromFile("BGforMenuE.png");
	menuBGtextE.setTexture(&ETexture);
	menuBGtextE.setOrigin(Vector2f(50.0f, 25.0f));
	menuBGtextE.setPosition(Vector2f(500.0f, 550.0f));

}

Mainmenu::~Mainmenu()
{
}


void Mainmenu::Run()
{
	if (this->menuBGtextNG.getGlobalBounds().contains(mousePosF))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{ 
			//Checkerror//
			printf("%d",forChangeWindow);
			forChangeWindow = 1;
		}
	}
	if (this->menuBGtextLS.getGlobalBounds().contains(mousePosF))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			printf("Load Save");
			forChangeWindow = 20;
		}
	}
	if (this->menuBGtextC.getGlobalBounds().contains(mousePosF))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			printf("Character");
			forChangeWindow = 30;
		}
	}
	if (this->menuBGtextE.getGlobalBounds().contains(mousePosF))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			exit = 1;
		}
	}
}

void Mainmenu::Draw(RenderWindow& window)
{
	window.draw(mainmenuBG);
	window.draw(menuBGtextNG);
	window.draw(menuBGtextLS);
	window.draw(menuBGtextC);
	window.draw(menuBGtextE);
	if (exit == 1)
	{ window.close(); }
}

void Mainmenu::Updatemousepos(RenderWindow& window)
{
	mousePos = Mouse::getPosition(window);
	Vector2f mousePos_F(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	mousePosF = mousePos_F;
}
