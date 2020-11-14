#include "Jump.h"

Jump::Jump(Texture* texture, Vector2u imageCount, float switchTime, float jumpspeed) :
	animationplayer(texture, imageCount, switchTime)
{
}

Jump::~Jump()
{
}
