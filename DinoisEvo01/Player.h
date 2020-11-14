#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
using namespace sf;
class Player
{
public:
	 Player(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpspeed);
	~Player();
	
	void Update(float deltatime);
	void Draw(RenderWindow& window);
	Vector2f Getpositionx() { return body.getPosition(); };

private:
	RectangleShape body;
	Animation animationplayer;
	unsigned int row;
	bool run;
	float speed;
	float jumpspeed;
};

