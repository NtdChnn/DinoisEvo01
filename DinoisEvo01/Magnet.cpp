#include "Magnet.h"

Magnet::Magnet()
{
	srand(time(NULL));

	magnetTexture.loadFromFile("Magnet.png");

	magnetpic.setTexture(&magnetTexture);
	magnetpic.setSize(Vector2f(40, 40));

	magnetpic0.setTexture(&magnetTexture);
	magnetpic0.setSize(Vector2f(40, 40));

	magnetpic1.setTexture(&magnetTexture);
	magnetpic1.setSize(Vector2f(40, 40));

	magnetpic2.setTexture(&magnetTexture);
	magnetpic2.setSize(Vector2f(40, 40));

	magnetpic3.setTexture(&magnetTexture);
	magnetpic3.setSize(Vector2f(40, 40));

	magnetpic4.setTexture(&magnetTexture);
	magnetpic4.setSize(Vector2f(40, 40));

}

Magnet::~Magnet()
{
}

void Magnet::Draw(RenderWindow& window)
{
	if (use == true)
	{
		window.draw(magnetpic0);
	}
	if (slot1 == 1)
	{
		window.draw(magnetpic1);
	}
	if (slot2 == 1)
	{
		window.draw(magnetpic2);
	}
	if (slot3 == 1)
	{
		window.draw(magnetpic3);
	}
	if (slot4 == 1)
	{
		window.draw(magnetpic4);
	}
}

void Magnet::SetpositionUse(Vector2f playerposition,Vector2f playerorgin, bool use)
{
	this->use = use;
	magnetpic0.setOrigin(playerorgin);
	magnetpic0.setPosition(playerposition.x, playerposition.y - 30);
}

void Magnet::SetpositionCollect(Vector2f playerposition, int slot1, int slot2, int slot3, int slot4)
{
	this->slot1 = slot1;
	this->slot2 = slot2;
	this->slot3 = slot3;
	this->slot4 = slot4;

	magnetpic1.setPosition(playerposition.x - 250, 50);
	magnetpic2.setPosition(playerposition.x - 200, 50);
	magnetpic3.setPosition(playerposition.x - 150, 50);
	magnetpic4.setPosition(playerposition.x - 100, 50);
}

void Magnet::Check(FloatRect playerGlobleBounds, int numItem)
{
	if (numItem < 4 && magnetpic.getGlobalBounds().intersects(playerGlobleBounds))
	{
		if (collision == false)
		{
			collision = true;
			numItem++;
			numMagnet++;
		}
	}
	else collision = false;

	this->numItem = numItem;
}
