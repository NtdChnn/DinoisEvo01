#include "Obstruction.h"

Obstruction::Obstruction(Texture* textureOb, Vector2f size , Vector2f position , int frequency, float distance)
{
	srand(time(NULL));
	obstrutction.setTexture(textureOb);
	obstrutction.setSize(size);
	obstrutction.setPosition(position);
	this->frequency = frequency;
	this->size = size;
	this->position = position;
	this->distance = distance;
}

Obstruction::~Obstruction()
{
}

void Obstruction::Draw(RenderWindow& window)
{
	if (obstrutction.getPosition().x < distance)
	{
		window.draw(obstrutction);
	}
	
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

void Obstruction::UpdateLife(int life)
{
	this->life = life;
}

void Obstruction::Restart()
{
	obstrutction.setSize(size);
	obstrutction.setPosition(position);
	life = 1;
}
