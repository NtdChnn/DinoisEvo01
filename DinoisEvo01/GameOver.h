#pragma once
#include <SFML\Graphics.hpp>
#include <windows.h>
#include <sstream> 
using namespace sf;
class GameOver
{
public:
	GameOver(int life);
	~GameOver();

	void CheckGameOver();
	void Draw(RenderWindow& window);
	bool statusGame() { return SGameover; };
	void GetplayerPosition(Vector2f playerPosition);

private:
	RectangleShape gameOverBG;
	Font gameFont;
	Text gameOverText;
	Text pressRtoRestartText;

	int life;
	bool SGameover = false;
};