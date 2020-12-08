#include "Obstruction.h"

Obstruction::Obstruction(Texture* textureOb, Vector2f size, Vector2f position)
{
	srand(time(NULL));
	obstrutction.setTexture(textureOb);
	obstrutction.setSize(size);
	obstrutction.setPosition(position);
}

Obstruction::~Obstruction()
{
}

void Obstruction::Draw(RenderWindow& window)
{
	window.draw(obstrutction);
}

bool Obstruction::Checkcollision(FloatRect player)
{
	if (obstrutction.getGlobalBounds().intersects(player))
	{
		collision = true;
	}
	else collision = false;

	return collision;
}
