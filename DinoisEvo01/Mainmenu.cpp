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
	menuBGtextNG.setFillColor(Color::Magenta);
	//NGTexture.loadFromFile("");
	//menuBGtextNG.setTexture(&NGTexture);
	menuBGtextNG.setOrigin(Vector2f(50.0f, 25.0f));
	menuBGtextNG.setPosition(Vector2f(250.0f, 350.0f));

	menuBGtextLS.setSize(Vector2f(150.0f, 50.0f));
	menuBGtextLS.setFillColor(Color::Red);
	//LSTexture.loadFromFile("");
	//menuBGtextLS.setTexture(&LSTexture);
	menuBGtextLS.setOrigin(Vector2f(50.0f, 25.0f));
	menuBGtextLS.setPosition(Vector2f(250.0f, 450.0f));

	menuBGtextC.setSize(Vector2f(150.0f, 50.0f));
	menuBGtextC.setFillColor(Color::Blue);
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
	if (this->menuBGtextNG.getGlobalBounds().contains(mousePos))
}


void Mainmenu::Run()
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

void Mainmenu::Updatemousepos(RenderWindow& window)
{
	mousePos = Mouse::getPosition(window);
	Vector2f mousePos_F(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	mousePosF = mousePos_F;
}
