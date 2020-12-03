#include "Stage.h"

Stage::Stage(Texture* playertexture, Vector2u imageCount, float switchTime, float speed, float jumpSpeed, Texture* BGtexture) :
	player(playertexture, imageCount, switchTime, speed, jumpSpeed), pause()
{
	srand(time(NULL));
	BG.setSize(Vector2f(13910,700));
	BG.setPosition(Vector2f(0.0f, 0.0f));
	BG.setTexture(BGtexture);
	obstruction.setPosition(Vector2f(1851,501));
}

Stage::~Stage()
{
}

void Stage::run(float deltaTime)
{
	if (pause.Getintpause() == 0)
	{
		player.Update(deltaTime);
	}
	pause.GetPlayerPosition(player.Getposition());
	pause.Setrun(player.Getrun());
	pause.checkPause();
}

void Stage::Draw(RenderWindow& window)
{

	window.draw(BG);
	player.Draw(window);
	pause.Draw(window);
}
