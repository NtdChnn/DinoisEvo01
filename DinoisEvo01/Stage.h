#pragma once
#include <SFML\Graphics.hpp>
#include <windows.h>
#include "Player.h"
#include "Pause.h"
#include "Mainmenu.h"
#include "Obstruction.h"
#include "GameOver.h"
#include "PlayerHitBox.h"
#include "Token.h"
#include "Restart.h"
using namespace sf;
using namespace std;
class Stage
{
public:
	Stage(Texture* playertexture, Vector2u imageCount, float switchTime, float speed, float jumpSpeed, float distance, Texture* BGtexture, Texture* Ob01texture, int frequency, int numOfToken);
	~Stage();

	void run(float deltaTime);
	void Draw(RenderWindow& window);
	Vector2f Getplayerposition() { return player.Getposition(); };

private:
	Player player;
	PlayerHitBox playerhitbox;
	RectangleShape BG;
	Obstruction Ob01;
	Pause pause;
	GameOver gameover;
	Token token;
	Restart restart;
	int life = 1 ;
	float distance;
};

