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
	if (show == true && magnetpic.getPosition().x < distance)
	{
		window.draw(magnetpic);
	}
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

void Magnet::SetpositionUse(Vector2f playerposition,Vector2f playerorigin, bool use)
{
	this->use = use;
	magnetpic0.setOrigin(playerorigin);
	magnetpic0.setPosition(playerposition.x+30, playerposition.y - 30);
}

void Magnet::SetpositionCollect(Vector2f playerposition, int slot1, int slot2, int slot3, int slot4)
{
	this->slot1 = slot1;
	this->slot2 = slot2;
	this->slot3 = slot3;
	this->slot4 = slot4;

	magnetpic1.setPosition(playerposition.x - 383, 55);
	magnetpic2.setPosition(playerposition.x - 330, 55);
	magnetpic3.setPosition(playerposition.x - 282, 55);
	magnetpic4.setPosition(playerposition.x - 230, 55);
}

void Magnet::SetpositionShow(Vector2f playerposition, FloatRect globleBoundsMeat, FloatRect globleBoundsVeggie, FloatRect globleBoundsOb, FloatRect globleBoundsShield, float distance)
{
	this->distance = distance;
	if (show == false)
	{
		magnetpic.setPosition(0, 0);
	}
	if (show == true)
	{
		if (checkshow == 1)
		{
			magnetpic.setPosition(playerposition.x + 500, 500);
			checkshow = 0;
		}
		if (magnetpic.getGlobalBounds().intersects(globleBoundsMeat) || magnetpic.getGlobalBounds().intersects(globleBoundsVeggie) || magnetpic.getGlobalBounds().intersects(globleBoundsOb) || magnetpic.getGlobalBounds().intersects(globleBoundsShield))
		{
			magnetpic.move(50, 0);
		}
	}
	//CheckERROR//
	//magnetpic.setPosition(500, 350);
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
			show = false;
		}
	}
	else collision = false;

	this->numItem = numItem;
}

void Magnet::Random(int percent)
{ 
	//CheckERROR//
	/*printf("%d", checkrand);
	if (rand() % 100 <= percent)
	{ checkrand = 1; } else checkrand = 0;*/
	if (show == false)
	{
		if (rand() % 10000000 <= percent)
		{
			show = true;
			checkshow = 1;
		}
	}
}
