#include "Stage.h"

Stage::Stage(Texture* playertexture, Vector2u imageCount, float switchTime, float speed, float jumpSpeed, Texture* BGtexture, Texture* Ob01texture) :
	player(playertexture, imageCount, switchTime, speed, jumpSpeed), pause(), Ob01(Ob01texture, Vector2f(118.0f, 37.3f), Vector2f(1851.0f, 501.0f))
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
	Ob01.Draw(window);
	player.Draw(window);
	pause.Draw(window);
}
