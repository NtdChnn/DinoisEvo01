#include "Stage.h"

Stage::Stage(Texture* playertexture, Vector2u imageCount, float switchTime, float speed, float jumpSpeed, float distance, Texture* BGtexture, Texture* Ob01texture, int frequency, int numOfToken, Texture* enemyTexture, Vector2u enemyImageCount, float enemySwitchTime, float enemySpeed) :
	player(playertexture, imageCount, switchTime, speed, jumpSpeed), pause(), gameover() , Ob01(Ob01texture, Vector2f(44.3, 74.0f),Vector2f(1000,470), frequency, distance), playerhitbox(Vector2f(60.0f,40.0f),player.GetOrigin()), token(numOfToken,distance), restart(), item(),enemy(enemyTexture,enemyImageCount,enemySwitchTime,enemySpeed)
{
	this->distance = distance;
	srand(time(NULL));
	BG.setSize(Vector2f(13910,700));
	BG.setPosition(Vector2f(0.0f, 0.0f));
	BG.setTexture(BGtexture);
}

Stage::~Stage()
{
}

void Stage::run(float deltaTime)
{
	//Check ERROR//
	//printf("\n %.2f", player.Getposition().x);
	if (pause.Getintpause() == 0 && gameover.statusGame() == false)
	{
		player.Update(deltaTime);

		enemy.Update(deltaTime);
		enemy.CheckCollision(playerhitbox.GetGlobalBounds());
		enemy.UpdatePosition(player.Getposition(), player.GetOrigin());

		item.Check(player.Getposition(), itemuse);
		item.Update(player.Getposition(), player.GetOrigin(), player.GetGlobalBounds(), token.GetGlobleBoundsTokenMeat(), token.GetGlobleBoundsTokenVeggie(), Ob01.GetGlobleBounds(), distance, 5);
		item.UpdateInventoryPosition(player.Getposition());
		//CheckERROR//
		//item.UpdateitemUsePosition(player.Getposition(), player.GetOrigin());
		//item.UpdateItemCollectPosition(player.Getposition());
		//item.UpdateItemShowPosition(player.Getposition(), token.GetGlobleBoundsTokenMeat(), token.GetGlobleBoundsTokenVeggie(), Ob01.GetGlobleBounds(), distance);

		//UseItem//
		//CheckERROR//
		//printf("%d", item.Use());
		if (item.Use() == 1) { itemuse = 1; }
		if (item.Use() == 2) { itemuse = 2; }
		if (item.Use() == 0) { itemuse = 0; }
		if (itemuse == 1) { token.Magnet(player.Getposition()); }
		if (itemuse == 2) { immortal = true; }
		if (playerhitbox.GetGlobalBounds().intersects(Ob01.GetGlobleBounds()) && itemuse == 2) { itemuse = 0; }
		if (life > 1 && itemuse == 0) { life = 1; immortal = false; }
	}

	if (restart.restartStatus() == true)
	{
		player.Restart();
		Ob01.Restart();
		gameover.Restart();
		token.Restart();
		item.Restart();
	}

		pause.GetPlayerPosition(player.Getposition());
		pause.Setrun(player.Getrun());
		pause.checkPause();

		playerhitbox.Update(player.Getposition());

		if (immortal == false)
		{
			gameover.GetplayerPosition(player.Getposition());
			gameover.CheckGameOver(Ob01.Getlife());
		}

		Ob01.Run(player.Getposition());
		Ob01.UpdateLife(life);
		Ob01.Checkcollision(playerhitbox.GetGlobalBounds());

		token.Update(playerhitbox.GetGlobalBounds(),player.Getposition());
		token.CheckOb(Ob01.GetGlobleBounds());

		restart.Check(gameover.statusGame());
}

void Stage::Draw(RenderWindow& window)
{
	window.draw(BG);
	Ob01.Draw(window);
	player.Draw(window);
	token.Draw(window);
	item.Draw(window);
	enemy.Draw(window);
	//CheckERROR//
	//playerhitbox.Draw(window);
	pause.Draw(window);
	gameover.Draw(window);
}
