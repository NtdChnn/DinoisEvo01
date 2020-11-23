#include "Stage.h"

Stage::Stage(Texture* playertexture, Vector2u imageCount, float switchTime, float speed, float jumpSpeed, Texture* BGtexture) :
	player(playertexture,imageCount,switchTime,speed,jumpSpeed)
{
	BG.setSize(Vector2f(13910,700));
	BG.setPosition(Vector2f(0.0f, 0.0f));
	BG.setTexture(BGtexture);
	obstruction.setSize(Vector2f(50, 50));
	obstruction.setPosition(Vector2f(1851,501));
}

Stage::~Stage()
{
}

void Stage::run(float deltaTime)
{
	player.Update(deltaTime);
}

void Stage::Draw(RenderWindow& window)
{
	window.draw(BG);
	window.draw(obstruction);
	player.Draw(window);
}
