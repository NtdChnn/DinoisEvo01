#include "Obstruction.h"

Obstruction::Obstruction(Texture* textureOb, Vector2f size, int frequency)
{
	srand(time(NULL));
	obstrutction.setTexture(textureOb);
	obstrutction.setSize(size);
	obstrutction.setPosition(1500, 500);
	this->frequency = frequency;
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
		//Check Error//
		//printf("Collision!");
		collision = true;
		life--;
	}
	else collision = false;

	return collision;
}

void Obstruction::Run(Vector2f playerPosition)
{
	float movex = 50 * (rand() % frequency);
	if (playerPosition.x > obstrutction.getPosition().x + 650)
	{
		//Check Error//
		//printf("Ob MOVE ! !");
		obstrutction.move(Vector2f(1100 + movex,0));
	}
}
