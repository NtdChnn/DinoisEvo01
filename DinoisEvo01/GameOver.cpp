#include "GameOver.h"

GameOver::GameOver()
{
	gameFont.loadFromFile("PixelEmulator-xq08.ttf");
	gameOverText.setFont(gameFont);
	gameOverText.setOutlineColor(Color::White);
	gameOverText.setOutlineThickness(5);
	gameOverText.setFillColor(Color::Black);
	gameOverText.setStyle(Text::Regular);
	gameOverText.setString("GAME OVER");
	gameOverText.setCharacterSize(100);

	pressRtoRestartText.setFont(gameFont);
	pressRtoRestartText.setOutlineColor(Color::White);
	pressRtoRestartText.setOutlineThickness(3);
	pressRtoRestartText.setFillColor(Color::Black);
	pressRtoRestartText.setStyle(Text::Regular);
	pressRtoRestartText.setString("Prees 'R' to restart");
	pressRtoRestartText.setCharacterSize(50);

	Color gameOverColor(255, 255, 255, 50);
	gameOverBG.setFillColor(gameOverColor);
	gameOverBG.setSize(Vector2f(1000.0f, 700.0f));
}

GameOver::~GameOver()
{
}

void GameOver::CheckGameOver(int life)
{
	if (life == 0)
	{
		SGameover = true;
	}
}

void GameOver::Draw(RenderWindow& window)
{
	if (SGameover == true)
	{
		window.draw(gameOverBG);
		window.draw(gameOverText);
		window.draw(pressRtoRestartText);
	}
}

void GameOver::GetplayerPosition(Vector2f playerPosition)
{
	gameOverBG.setPosition(playerPosition.x - 500, 0);
	gameOverText.setPosition(playerPosition.x - 325, 200);
	pressRtoRestartText.setPosition(playerPosition.x - 325, 300);
}

void GameOver::Restart()
{
	SGameover = false;
}
