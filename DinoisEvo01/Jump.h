#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
using namespace sf;
class Jump
{
public :
	Jump(Texture* texture, Vector2u imageCount, float switchTime, float jumpspeed);
	~Jump();

private : 
	Animation animationplayer;
};

