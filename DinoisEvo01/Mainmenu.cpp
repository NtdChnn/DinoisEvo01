#include "Mainmenu.h"

Mainmenu::Mainmenu()
{
	gameFont.loadFromFile("PixelEmulator-xq08.ttf");

	mainmenuBG.setSize(Vector2f(1000.0f, 700.0f));
	BGtexture.loadFromFile("BGforMenu.png");
	mainmenuBG.setTexture(&BGtexture);
	mainmenuBG.setOrigin(Vector2f(0.0f, 0.0f));
	mainmenuBG.setPosition(Vector2f(0.0f, 0.0f));

	menuBGtextNG.setSize(Vector2f(150.0f, 50.0f));
	NGTexture.loadFromFile("BGforMenuNG.png");
	menuBGtextNG.setTexture(&NGTexture);
	menuBGtextNG.setOrigin(Vector2f(50.0f, 25.0f));
	menuBGtextNG.setPosition(Vector2f(500.0f, 300.0f));

	menuTextNewGame.setFont(gameFont);
	menuTextNewGame.setOutlineColor(Color::White);
	menuTextNewGame.setOutlineThickness(2);
	menuTextNewGame.setFillColor(Color::Black);
	menuTextNewGame.setStyle(Text::Regular);
	menuTextNewGame.setString("New Game");
	menuTextNewGame.setCharacterSize(25);
	menuTextNewGame.setPosition(Vector2f(500.0f, 300.0f));
	menuTextNewGame.setOrigin(Vector2f(50.0f, 25.0f));

	menuBGtextS.setSize(Vector2f(60.0f, 50.0f));
	STexture.loadFromFile("BGforMenuC.png");
	menuBGtextS.setTexture(&STexture);
	menuBGtextS.setOrigin(Vector2f(30.0f, 25.0f));
	menuBGtextS.setPosition(Vector2f(510.0f, 350.0f));

	menuTextStage.setFont(gameFont);
	menuTextStage.setOutlineColor(Color::White);
	menuTextStage.setOutlineThickness(2);
	menuTextStage.setFillColor(Color::Black);
	menuTextStage.setStyle(Text::Regular);
	menuTextStage.setString("Stage");
	menuTextStage.setCharacterSize(25);
	menuTextStage.setPosition(Vector2f(510.0f, 350.0f));
	menuTextStage.setOrigin(Vector2f(30.0f, 25.0f));

	menuBGtextLDB.setSize(Vector2f(150.0f, 50.0f));
	LDBTexture.loadFromFile("BGforMenuLS.png");
	menuBGtextLDB.setTexture(&LDBTexture);
	menuBGtextLDB.setOrigin(Vector2f(75.0f, 25.0f));
	menuBGtextLDB.setPosition(Vector2f(470.0f, 400.0f));

	menuTextLeaderBoard.setFont(gameFont);
	menuTextLeaderBoard.setOutlineColor(Color::White);
	menuTextLeaderBoard.setOutlineThickness(2);
	menuTextLeaderBoard.setFillColor(Color::Black);
	menuTextLeaderBoard.setStyle(Text::Regular);
	menuTextLeaderBoard.setString("LeaderBoard");
	menuTextLeaderBoard.setCharacterSize(25);
	menuTextLeaderBoard.setPosition(Vector2f(500.0f, 400.0f));
	menuTextLeaderBoard.setOrigin(Vector2f(75.0f, 25.0f));

	menuBGtextE.setSize(Vector2f(60.0f, 50.0f));
	ETexture.loadFromFile("BGforMenuE.png");
	menuBGtextE.setTexture(&ETexture);
	menuBGtextE.setOrigin(Vector2f(30.0f, 25.0f));
	menuBGtextE.setPosition(Vector2f(510.0f, 550.0f));

	menuTextExit.setFont(gameFont);
	menuTextExit.setOutlineColor(Color::White);
	menuTextExit.setOutlineThickness(2);
	menuTextExit.setFillColor(Color::Black);
	menuTextExit.setStyle(Text::Regular);
	menuTextExit.setString("Exit");
	menuTextExit.setCharacterSize(25);
	menuTextExit.setPosition(Vector2f(510.0f, 550.0f));
	menuTextExit.setOrigin(Vector2f(25.0f, 25.0f));

}

Mainmenu::~Mainmenu()
{
}


void Mainmenu::Run()
{
	if (this->menuBGtextNG.getGlobalBounds().contains(mousePosF) || Keyboard::isKeyPressed(Keyboard::Key::N))
	{
		menuTextNewGame.setOutlineColor(Color::White);
		menuTextNewGame.setFillColor(Color::Red);
		menuTextNewGame.setCharacterSize(30);
		menuTextNewGame.setPosition(Vector2f(490.0f, 300.0f));
		if (Mouse::isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Key::N))
		{ 
			//Checkerror//
			//printf("%d",forChangeWindow);
			forChangeWindow = 1;
		}
	}
	else {
		menuTextNewGame.setOutlineColor(Color::White);
		menuTextNewGame.setFillColor(Color::Black);
		menuTextNewGame.setCharacterSize(25);
		menuTextNewGame.setPosition(Vector2f(500.0f, 300.0f));
	}
	if (this->menuBGtextLDB.getGlobalBounds().contains(mousePosF))
	{
		menuTextLeaderBoard.setOutlineColor(Color::White);
		menuTextLeaderBoard.setFillColor(Color::Red);
		menuTextLeaderBoard.setCharacterSize(30);
		menuTextLeaderBoard.setPosition(Vector2f(480.0f, 400.0f));
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			printf("LeaderBoard");
			forChangeWindow = 20;
		}
	}
	else {
		menuTextLeaderBoard.setOutlineColor(Color::White);
		menuTextLeaderBoard.setFillColor(Color::Black);
		menuTextLeaderBoard.setCharacterSize(25);
		menuTextLeaderBoard.setPosition(Vector2f(500.0f, 400.0f));
	}
	if (this->menuBGtextS.getGlobalBounds().contains(mousePosF))
	{
		menuTextStage.setOutlineColor(Color::White);
		menuTextStage.setFillColor(Color::Red);
		menuTextStage.setCharacterSize(30);
		menuTextStage.setPosition(Vector2f(500.0f, 350.0f));
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			printf("Character");
			forChangeWindow = 30;
		}
	}
	else
	{
		menuTextStage.setOutlineColor(Color::White);
		menuTextStage.setFillColor(Color::Black);
		menuTextStage.setCharacterSize(25);
		menuTextStage.setPosition(Vector2f(510.0f, 350.0f));
	}
	if (this->menuBGtextE.getGlobalBounds().contains(mousePosF))
	{
		menuTextExit.setOutlineColor(Color::White);
		menuTextExit.setFillColor(Color::Red);
		menuTextExit.setCharacterSize(30);
		menuTextExit.setPosition(Vector2f(510.0f, 550.0f));
		if (Mouse::isButtonPressed(Mouse::Left))
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			exit = 1;
		}
	}
	else
	{
		menuTextExit.setOutlineColor(Color::White);
		menuTextExit.setFillColor(Color::Black);
		menuTextExit.setCharacterSize(25);
		menuTextExit.setPosition(Vector2f(515.0f, 550.0f));
	}
}

void Mainmenu::Draw(RenderWindow& window)
{
	window.draw(mainmenuBG);
	window.draw(menuTextNewGame);
	window.draw(menuTextLeaderBoard);
	window.draw(menuTextStage);
	window.draw(menuTextExit);
	if (exit == 1)
	{ window.close(); }
}

void Mainmenu::Updatemousepos(RenderWindow& window)
{
	mousePos = Mouse::getPosition(window);
	Vector2f mousePos_F(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	mousePosF = mousePos_F;
}
