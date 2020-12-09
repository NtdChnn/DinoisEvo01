#include "Obstruction.h"

Obstruction::Obstruction(Texture* textureOb, Vector2f size , Vector2f position , int frequency)
{
	srand(time(NULL));
	obstrutction.setTexture(textureOb);
	obstrutction.setSize(size);
	obstrutction.setPosition(position);
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
	float movex = 100 * (rand() % frequency);
	if (playerPosition.x > obstrutction.getPosition().x + 650)
	{
		//Check Error//
		//printf("Ob MOVE ! !");
		obstrutction.move(Vector2f(1100 + movex,0));
	}
}
