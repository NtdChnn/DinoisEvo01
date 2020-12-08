#pragma once
#include <SFML\Graphics.hpp>
#include <windows.h>
#include "Player.h"
#include "Pause.h"
#include "Mainmenu.h"
#include "Obstruction.h"
#include "GameOver.h"
using namespace sf;
using namespace std;
class Stage
{
public:
	Stage(Texture* playertexture, Vector2u imageCount, float switchTime, float speed, float jumpSpeed, Texture* BGtexture, Texture* Ob01texture, int frequency);
	~Stage();

	void run(float deltaTime);
	void Draw(RenderWindow& window);
	Vector2f Getplayerposition() { return player.Getposition(); };
	int GetGameover() { return life; }

private:
	Player player;
	RectangleShape BG;
	Obstruction Ob01;
	Pause pause;
	GameOver gameover;
	int life;
};

