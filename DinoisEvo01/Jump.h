#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
using namespace sf;
class Jump
{
public :
	Jump(Texture* texture, Vector2u imageCount, float switchTime, float jumpspeed);
	~Jump();

	void Update(float deltatime);
	void Draw(RenderWindow& window);
	Vector2f Getpositionx() { return body.getPosition(); };

private : 
	Animation animationplayer;
};

