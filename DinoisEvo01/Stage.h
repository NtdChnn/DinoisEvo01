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
#include "Item.h"
#include "Enemy.h"
#include "StageComplete.h"

using namespace sf;
using namespace std;
class Stage
{
public:
	Stage(Texture* playertexture, Vector2u imageCount, Vector2f sizePlayer, float switchTime, float speed, float jumpSpeed, float distance, Texture* BGtexture, Texture* Ob01texture, int frequency, int numOfToken,Texture* tokenTexture01,Texture* tokenTexture02, Vector2f sizeToken01, Vector2f sizeToken02,Texture* enemyTexture, Vector2u enemyImageCount, float enemySwitchTime, float enemySpeed);
	~Stage();

	void run(float deltaTime);
	void Draw(RenderWindow& window);
	Vector2f Getplayerposition() { return player.Getposition(); };
	int GetForChangeWindow() { return forChangeWindow; }
	int GetCheckForChangeWindow() { return checkForChangWindow; }
	void UpdateForChangeWindow(int forChangeWindow) { this->forChangeWindow = forChangeWindow; }
	void UpdateWindowNow(int windowNow) { this->windowNow = windowNow; };
	bool GetActive() { return Active; };
	int GetStageComplete() { return stageComplete; };
	int GetNextStage() { return nextStage; };
private:
	Player player;
	PlayerHitBox playerhitbox;

	RectangleShape BG;

	Obstruction Ob01;
	Pause pause;
	GameOver gameover;
	Token token;
	Restart restart;
	Item item;
	Enemy enemy;
	StageComplete stagecomplete;

	RenderWindow window;
	
	int checkForChangWindow = 0;
	int forChangeWindow = 0;
	int windowNow;
	int itemuse = 0;
	int life = 1 ;
	float distance;
	bool immortal = false;
	bool Run = false;
	int nextStage = 0;
	int stageComplete = 0;

	bool Active = false;
};

