#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Pause.h"
using namespace sf;
using namespace std;
class Stage
{
public:
	Stage(Texture* playertexture, Vector2u imageCount, float switchTime, float speed, float jumpSpeed, Texture* BGtexture);
	~Stage();

	void run(float deltaTime);
	void Draw(RenderWindow& window);
	Vector2f Getplayerposition() { return player.Getposition(); };

private:
	Player player;
	RectangleShape BG;
	RectangleShape obstruction;
	Pause pause;
};

