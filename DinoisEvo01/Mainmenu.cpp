#include "Mainmenu.h"

Mainmenu::Mainmenu()
{
	mainmenuBG.setSize(Vector2f(1000.0f, 700.0f));
	mainmenuBG.setFillColor(Color::Black);
	//BGtexture.loadFromFile("");
	//mainmenuBG.setTexture(&BGtexture);
	mainmenuBG.setOrigin(Vector2f(0.0f, 0.0f));
	mainmenuBG.setPosition(Vector2f(0.0f, 0.0f));

	menuBGtextNG.setSize(Vector2f(150.0f, 50.0f));
	menuBGtextNG.setFillColor(Color::White);
	//NGTexture.loadFromFile("");
	//menuBGtextNG.setTexture(&NGTexture);
	menuBGtextNG.setOrigin(Vector2f(50.0f, 25.0f));
	menuBGtextNG.setPosition(Vector2f(250.0f, 350.0f));

	menuBGtextLS.setSize(Vector2f(150.0f, 50.0f));
	menuBGtextLS.setFillColor(Color::White);
	//LSTexture.loadFromFile("");
	//menuBGtextLS.setTexture(&LSTexture);
	menuBGtextLS.setOrigin(Vector2f(50.0f, 25.0f));
	menuBGtextLS.setPosition(Vector2f(250.0f, 450.0f));

	menuBGtextC.setSize(Vector2f(150.0f, 50.0f));
	menuBGtextC.setFillColor(Color::White);
	//CTexture.loadFromFile("");
	//menuBGtextC.setTexture(&CTexture);
	menuBGtextC.setOrigin(Vector2f(50.0f, 25.0f));
	menuBGtextC.setPosition(Vector2f(750.0f, 350.0f));

	menuBGtextE.setSize(Vector2f(150.0f, 50.0f));
	menuBGtextE.setFillColor(Color::White);
	//ETexture.loadFromFile("");
	//menuBGtextE.setTexture(&ETexture);
	menuBGtextE.setOrigin(Vector2f(50.0f, 25.0f));
	menuBGtextE.setPosition(Vector2f(500.0f, 550.0f));
}

Mainmenu::~Mainmenu()
{
}

void Mainmenu::Draw(RenderWindow& window)
{
	window.draw(mainmenuBG);
	window.draw(menuBGtextNG);
	window.draw(menuBGtextLS);
	window.draw(menuBGtextC);
	window.draw(menuBGtextE);
}
