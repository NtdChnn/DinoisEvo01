#include "Stage.h"

Stage::Stage(Texture* playertexture, Vector2u imageCount, float switchTime, float speed, float jumpSpeed, Texture* BGtexture, Texture* Ob01texture, int frequency) :
	player(playertexture, imageCount, switchTime, speed, jumpSpeed), pause(), gameover() , Ob01(Ob01texture, Vector2f(70.0f, 50.0f), frequency), playerhitbox(Vector2f(80.0f,40.0f),player.GetOrigin())
{
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
	if (pause.Getintpause() == 0 && gameover.statusGame() == false)
	{
		player.Update(deltaTime);
	}
		pause.GetPlayerPosition(player.Getposition());
		pause.Setrun(player.Getrun());
		pause.checkPause();
		playerhitbox.Update(player.Getposition());
		gameover.GetplayerPosition(player.Getposition());
		gameover.CheckGameOver(Ob01.Getlife());
		Ob01.Run(player.Getposition());
		Ob01.Checkcollision(playerhitbox.GetGlobalBounds());

}

void Stage::Draw(RenderWindow& window)
{
	window.draw(BG);
	Ob01.Draw(window);
	player.Draw(window);
	//CheckERROR//
	//playerhitbox.Draw(window);
	pause.Draw(window);
	gameover.Draw(window);
}
