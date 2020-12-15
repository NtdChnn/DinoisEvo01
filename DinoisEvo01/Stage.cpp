#include "Stage.h"

Stage::Stage(Texture* playertexture, Vector2u imageCount, Vector2f sizePlayer, float switchTime, float speed, float jumpSpeed, float distance, Texture* BGtexture, Texture* Ob01texture, int frequency, int numOfToken, Texture* tokenTexture01, Texture* tokenTexture02,Vector2f sizeToken01,Vector2f sizeToken02, Texture* enemyTexture, Vector2u enemyImageCount, float enemySwitchTime, float enemySpeed) :
	player(playertexture, imageCount,sizePlayer, switchTime, speed, jumpSpeed), pause(), gameover() , Ob01(Ob01texture, Vector2f(44.3, 74.0f),Vector2f(1000,470), frequency, distance), playerhitbox(Vector2f(60.0f,40.0f),player.GetOrigin()), token(numOfToken,distance,tokenTexture01,tokenTexture02,sizeToken01,sizeToken02), restart(), item(),enemy(enemyTexture,enemyImageCount,enemySwitchTime,enemySpeed),stagecomplete()
{
	srand(time(NULL));

	this->distance = distance;
	srand(time(NULL));
	BG.setSize(Vector2f(15000,700));
	BG.setPosition(Vector2f(0.0f, 0.0f));
	BG.setTexture(BGtexture);
}

Stage::~Stage()
{
}

void Stage::run(float deltaTime)
{
	Active = true;
	forChangeWindow = 0;
	Run = player.Getrun();
	//printf("%d\n", token.GetforTotalScore());
	//Check ERROR//
	//printf("\n %.2f", player.Getposition().x);
	if (pause.Getintpause() == 0 && gameover.statusGame() == false && stagecomplete.GetRun() == false)
	{
		player.Update(deltaTime);

		enemy.Update(deltaTime);
		enemy.CheckCollision(playerhitbox.GetGlobalBounds());
		enemy.UpdatePosition(player.Getposition(), player.GetOrigin());
		if (enemy.Collosion() == true) { life--; }

		Ob01.Run(player.Getposition());
		Ob01.UpdateLife(life);
		Ob01.Checkcollision(playerhitbox.GetGlobalBounds());
		if (Ob01.Collision() == true) { life--; }

		//Item//
		{
			item.Check(player.Getposition(), itemuse);
			item.Update(player.Getposition(), player.GetOrigin(), player.GetGlobalBounds(), token.GetGlobleBoundsTokenMeat(), token.GetGlobleBoundsTokenVeggie(), Ob01.GetGlobleBounds(), distance, 5);
			item.UpdateInventoryPosition(player.Getposition());
			/*
			//CheckERROR//
			//item.UpdateitemUsePosition(player.Getposition(), player.GetOrigin());
			//item.UpdateItemCollectPosition(player.Getposition());
			//item.UpdateItemShowPosition(player.Getposition(), token.GetGlobleBoundsTokenMeat(), token.GetGlobleBoundsTokenVeggie(), Ob01.GetGlobleBounds(), distance);

			//UseItem//
			//CheckERROR//
			//printf("%d\n", item.Use()); */
			if (item.Use() == 1) { itemuse = 1; }
			if (item.Use() == 2) { itemuse = 2; }
			if (item.Use() == 0) { itemuse = 0; }
			//printf("%d\n", itemuse);
			if (itemuse == 1) { token.Magnet(player.Getposition()); }
			if (itemuse == 2) { life++; immortal = true; }
			/*if (playerhitbox.GetGlobalBounds().intersects(Ob01.GetGlobleBounds()) && itemuse == 2 && immortal == true)
			{ itemuse = 3; }
			//if (!playerhitbox.GetGlobalBounds().intersects(Ob01.GetGlobleBounds()) && itemuse == 3 && immortal == true)
			//{ itemuse = 0; }
			if (enemy.Collostion() == true && itemuse == 2 && immortal == true)
			{ itemuse = 3; }
			//if (enemy.Collostion() == false && itemuse == 3 && immortal == true)
			//{ itemuse = 0; } */
			//printf("%d\n", itemuse);
			if (life >= 1 && itemuse == 0) { life = 1;  immortal = false; }
		}

		if (player.Getposition().x >= distance)
		{
			nextStage = 0;
			if (token.numToken01() == token.numToken02())
			{
				if (stageComplete == 0)
				{
					stageComplete = (rand() % 1) + 1;
					nextStage = (rand() % 1) + 1;
				}
				else if (stageComplete == 1 || stageComplete == 2)
				{
					stageComplete = 3;
					nextStage = (rand() % 1) + 1;
				}
			}
			if (token.numToken01() > token.numToken02())
			{
				nextStage = 1;
				if (stageComplete == 0 || stageComplete == 1)
				{
					stageComplete = 1;
				}
				else if (stageComplete == 2)
				{
					stageComplete = 3;
				}
			}
			else if (token.numToken02() > token.numToken01())
			{
				nextStage = 2;
				if (stageComplete == 0 || stageComplete == 2)
					{
						stageComplete = 2;
					}
					else if (stageComplete == 1)
					{
						stageComplete = 3;
					}
			}
		}
	}
	
	stagecomplete.Update(distance, player.Getposition(), token.numToken01(), token.numToken02());

	if (stagecomplete.GetForChangeWindow() == 20)
	{
		forChangeWindow = 20;
		//printf("%d", forChangeWindow);
		Active = false;
	}
	else if (stagecomplete.GetForChangeWindow() == 11)
	{
		forChangeWindow = 11;
		Active = false;
	}

	pause.GetPlayerPosition(player.Getposition());
	pause.Setrun(Run);
	pause.checkPause();
	if (pause.GetForChangewindow() == 99)
	{
		forChangeWindow = 99;
		Active = false;
	}

	if (Active == false || stagecomplete.GetRetry() == true)
	{
		player.Restart();
		Ob01.Restart();
		gameover.Restart();
		token.Restart();
		item.Restart();
		enemy.Restart();
		itemuse = 0;
		life = 1;
		Run = false;
		player.UpdateRun(Run);
	}

	restart.CheckGameOver(gameover.statusGame());
	if (restart.restartStatus() == true )
	{
		player.Restart();
		Ob01.Restart();
		gameover.Restart();
		token.Restart();
		item.Restart();
		enemy.Restart();
		itemuse = 0;
		life = 1;
	}

		playerhitbox.Update(player.Getposition());

		if (immortal == false && player.Getposition().x <= distance)
		{
			gameover.GetplayerPosition(player.Getposition());
			gameover.CheckGameOver(Ob01.Getlife());
		}

		token.Update(playerhitbox.GetGlobalBounds(),player.Getposition());
		token.CheckOb(Ob01.GetGlobleBounds());
}

void Stage::Draw(RenderWindow& window)
{
	pause.Updatemousepos(window);
	stagecomplete.Updatemousepos(window);
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
	stagecomplete.Draw(window);
}
