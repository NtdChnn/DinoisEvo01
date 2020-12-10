#include "Item.h"

Item::Item() :
	magnet(), shield()
{
	inventoryTexture.loadFromFile("inventory.png");
	inventory.setTexture(&inventoryTexture);
	inventory.setSize(Vector2f(228.5f, 71.4f));
}

Item::~Item()
{
}

void Item::Update(Vector2f playerPosition, Vector2f playerOrigin, FloatRect playerGlobleBounds, FloatRect tokenMeatGlobleBounds, FloatRect tokenVeggieGlobleBounds, FloatRect ObGlobleBounds, float distance, int percent)
{
	this->playerPosition = playerPosition;

	inventory.setPosition(playerPosition.x - 270, 40);

	magnet.SetpositionCollect(playerPosition, slot1, slot2, slot3, slot4);
	magnet.SetpositionShow(playerPosition, tokenMeatGlobleBounds, tokenVeggieGlobleBounds, ObGlobleBounds, distance);
	magnet.SetpositionUse(playerPosition, playerOrigin, useMagnet);
	magnet.Random(percent);
	magnet.Check(playerGlobleBounds, numOfItem);

	shield.SetpositionCollect(playerPosition, slot1, slot2, slot3, slot4);
	shield.SetpositionShow(playerPosition, tokenMeatGlobleBounds, tokenVeggieGlobleBounds, ObGlobleBounds, distance);
	shield.SetpositionUse(playerPosition, playerOrigin, useShield);
	shield.Random(percent);
	shield.Check(playerGlobleBounds, numOfItem);
}

void Item::Check(Vector2f playerPosition)
{
	if (slot1 == 0 && collisionMagnet == true)
	{
		slot1 = 1; numOfItem++;
	}
	else if (slot1 == 0 && collisionShield == true)
	{
		slot1 = 2; numOfItem++;
	} 
	else if(slot2 == 0 && collisionMagnet == true)
	{
		slot2 = 1; numOfItem++;
	}
	else if (slot2 == 0 && collisionShield == true)
	{
		slot2 = 2; numOfItem++;
	}
	else if (slot3 == 0 && collisionMagnet == true)
	{
		slot3 = 1; numOfItem++;
	}
	else if (slot3 == 0 && collisionShield == true)
	{
		slot3 = 2; numOfItem++;
	}
	else if (slot4 == 0 && collisionMagnet == true)
	{
		slot4 = 1; numOfItem++;
	}
	else if (slot4 == 0 && collisionShield == true)
	{
		slot4 = 2; numOfItem++;
	}


	if (Keyboard::isKeyPressed(Keyboard::Key::Num1) && useMagnet == false && useShield == false && slot1 != 0)
	{
		//CheckERROR//
		//printf("1");
		if (slot1 == 1)
		{
			useItem = 1;
			useMagnet = true; numOfItem--;
		}
		if (slot1 == 2)
		{
			useItem = 2;
			useShield = true; numOfItem--;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Num2) && useMagnet == false && useShield == false && slot2 != 0)
	{
		//CheckERROR//
		//printf("2");
		if (slot2 == 1)
		{
			useItem = 1;
			useMagnet = true; numOfItem--;
		}
		if (slot2 == 2)
		{
			useItem = 2;
			useShield = true; numOfItem--;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Num3) && useMagnet == false && useShield == false && slot3 != 0)
	{
		//CheckERROR//
		//printf("3");
		if (slot3 == 1)
		{
			useItem = 1;
			useMagnet = true; numOfItem--;
		}
		if (slot3 == 2)
		{
			useItem = 2;
			useShield = true; numOfItem--;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Num4) && useMagnet == false && useShield == false && slot4 != 0)
	{
		//CheckERROR//
		//printf("4");
		if (slot4 == 1)
		{
			useItem = 1;
			useMagnet = true; numOfItem--;
		}
		if (slot4 == 2)
		{
			useItem = 2;
			useShield = true; numOfItem--;
		}
	}

	if (useItem == 1 || useItem == 2)
	{
		checkDistance = playerPosition.x + 500;
		useItem = 3;
	}
	if (useItem == 3 && playerPosition.x == checkDistance)
	{
		useItem = 0;
		useMagnet = false;
		useShield = false;
	}
}

void Item::Draw(RenderWindow& window)
{
	window.draw(inventory);
	magnet.Draw(window);
	shield.Draw(window);
}
