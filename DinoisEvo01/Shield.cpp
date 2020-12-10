#include "Shield.h"

Shield::Shield()
{
	srand(time(NULL));

	shieldTexture.loadFromFile("shield.png");

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
	if (show == true && shieldpic.getPosition().x < distance)
	{
		window.draw(shieldpic);
	}
	if (use == true)
	{
		window.draw(shieldpic0);
	}
	if (slot1 == 2)
	{
		window.draw(shieldpic1);
	}
	if (slot2 == 2)
	{
		window.draw(shieldpic2);
	}
	if (slot3 == 2)
	{
		window.draw(shieldpic3);
	}
	if (slot4 == 2)
	{
		window.draw(shieldpic4);
	}
}

void Shield::SetpositionUse(Vector2f playerposition, Vector2f playerorigin, bool use)
{
	this->use = use;
	shieldpic0.setOrigin(playerorigin);
	shieldpic0.setPosition(playerposition.x+30, playerposition.y - 30);
}

void Shield::SetpositionCollect(Vector2f playerposition, int slot1, int slot2, int slot3, int slot4)
{
	this->slot1 = slot1;
	this->slot2 = slot2;
	this->slot3 = slot3;
	this->slot4 = slot4;

	shieldpic1.setPosition(playerposition.x - 383, 55);
	shieldpic2.setPosition(playerposition.x - 330, 55);
	shieldpic3.setPosition(playerposition.x - 282, 55);
	shieldpic4.setPosition(playerposition.x - 230, 55);
}

void Shield::SetpositionShow(Vector2f playerposition, FloatRect globleBoundsMeat, FloatRect globleBoundsVeggie, FloatRect globleBoundsOb, float distance)
{
	this->distance = distance;
	if (show == false)
	{
		shieldpic.setPosition(0, 0);
	}
	if (show == true)
	{
		if (checkshow == 1)
		{
			shieldpic.setPosition(playerposition.x + 500, 500);
			checkshow = 0;
		}
		if (shieldpic.getGlobalBounds().intersects(globleBoundsMeat) || shieldpic.getGlobalBounds().intersects(globleBoundsVeggie) || shieldpic.getGlobalBounds().intersects(globleBoundsOb))
		{
			shieldpic.move(50, 0);
		}
	}
	//CheckERROR//
	//shieldpic.setPosition(500, 350);
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
			show = false;
		}
	}
	else collision = false;

	this->numItem = numItem;
}

void Shield::Random(int percent)
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

