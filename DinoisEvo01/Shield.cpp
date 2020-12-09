#include "Shield.h"

Shield::Shield()
{
	shieldTexture.loadFromFile("shield - removebg - preview.png");

	shieldpic.setTexture(&shieldTexture);
	shieldpic.setSize(Vector2f(40, 40));

	shieldpic0.setTexture(&shieldTexture);
	shieldpic0.setSize(Vector2f(40, 40));

	shieldpic1.setTexture(&shieldTexture);
	shieldpic1.setSize(Vector2f(40, 40));

	shieldpic2.setTexture(&shieldTexture);
	shieldpic2.setSize(Vector2f(40, 40));

	shieldpic3.setTexture(&shieldTexture);
	shieldpic3.setSize(Vector2f(40, 40));

	shieldpic4.setTexture(&shieldTexture);
	shieldpic4.setSize(Vector2f(40, 40));

}

Shield::~Shield()
{
}

void Shield::Draw(RenderWindow& window)
{
	if (use == true)
	{
		window.draw(shieldpic0);
	}
	if (slot1 == 1)
	{
		window.draw(shieldpic1);
	}
	if (slot2 == 1)
	{
		window.draw(shieldpic2);
	}
	if (slot3 == 1)
	{
		window.draw(shieldpic3);
	}
	if (slot4 == 1)
	{
		window.draw(shieldpic4);
	}
}

void Shield::SetpositionUse(Vector2f playerposition, Vector2f playerorigin, bool use)
{
	this->use = use;
	shieldpic0.setOrigin(playerorigin);
	shieldpic0.setPosition(playerposition.x, playerposition.y - 30);
}

void Shield::SetpositionCollect(Vector2f playerposition, int slot1, int slot2, int slot3, int slot4)
{
	this->slot1 = slot1;
	this->slot2 = slot2;
	this->slot3 = slot3;
	this->slot4 = slot4;

	shieldpic1.setPosition(playerposition.x - 250, 50);
	shieldpic2.setPosition(playerposition.x - 200, 50);
	shieldpic3.setPosition(playerposition.x - 150, 50);
	shieldpic4.setPosition(playerposition.x - 100, 50);
}

void Shield::Check(FloatRect playerGlobleBounds, int numItem)
{
	if (numItem < 4 && shieldpic.getGlobalBounds().intersects(playerGlobleBounds))
	{
		if (collision == false)
		{
			collision = true;
			numItem++;
			numShield++;
		}
	}
	else collision = false;

	this->numItem = numItem;
}

