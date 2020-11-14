#include "Jump.h"

Jump::Jump(Texture* texture, Vector2u imageCount, float switchTime, float jumpspeed) :
	animationplayer(texture, imageCount, switchTime)
{
}

Jump::~Jump()
{
}

void Jump::Update(float deltatime)
{
}

void Jump::Draw(RenderWindow& window)
{
}
