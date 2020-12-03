#include "Obstruction.h"

Obstruction::Obstruction(Texture* textureOb, Vector2f size, int frequency)
{
	srand(time(NULL));
	this->frequency = frequency;
	//obstrutction.setTexture(textureOb);
	//obstrutction.setSize(size);


}

Obstruction::~Obstruction()
{
}

void Obstruction::Draw(RenderWindow& window)
{
	window.draw(obstrutction);
}
