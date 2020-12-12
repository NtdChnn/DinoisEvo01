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

	magnet.Random(1);
	magnet.SetpositionCollect(playerPosition, slot1, slot2, slot3, slot4);
	magnet.SetpositionUse(playerPosition, playerOrigin, useMagnet);
	magnet.SetpositionShow(playerPosition, tokenMeatGlobleBounds, tokenVeggieGlobleBounds, ObGlobleBounds, shield.GetGlobleBounds(), distance);
	magnet.Check(playerGlobleBounds, numOfItem);

	shield.Random(1);
	shield.SetpositionCollect(playerPosition, slot1, slot2, slot3, slot4);
	shield.SetpositionUse(playerPosition, playerOrigin, useShield);
	shield.SetpositionShow(playerPosition, tokenMeatGlobleBounds, tokenVeggieGlobleBounds, ObGlobleBounds, distance);
	shield.Check(playerGlobleBounds, numOfItem);

	inventory.setPosition(playerPosition.x - 400, 40);
}

//CheckERROR//
void Item::UpdateInventoryPosition(Vector2f playerPosition)
{
	inventory.setPosition(playerPosition.x - 400, 40);
}

void Item::UpdateItemShowPosition(Vector2f playerPosition, FloatRect tokenMeatGlobleBounds, FloatRect tokenVeggieGlobleBounds, FloatRect ObGlobloBounds, float distance)
{
	magnet.SetpositionShow(playerPosition, tokenMeatGlobleBounds, tokenVeggieGlobleBounds, ObGlobloBounds, shield.GetGlobleBounds(), distance);
	shield.SetpositionShow(playerPosition, tokenMeatGlobleBounds, tokenVeggieGlobleBounds, ObGlobloBounds, distance);
}

void Item::UpdateItemUsePosition(Vector2f playerPosition, Vector2f playerOrigin)
{
	shield.SetpositionUse(playerPosition, playerOrigin,useShield);
	magnet.SetpositionUse(playerPosition, playerOrigin,useMagnet);
}

void Item::UpdateItemCollectPosition(Vector2f playerPosition)
{
	magnet.SetpositionCollect(playerPosition, slot1, slot2, slot3, slot4);
	shield.SetpositionCollect(playerPosition, slot1, slot2, slot3, slot4);
}

void Item::Check(Vector2f playerPosition, int useItem)
{
	//CheckERROR//
	//printf("%d %d %d %d \n",slot1, slot2,slot3,slot4);
	collisionMagnet = magnet.Collision();
	collisionShield = shield.Collision();

	if (slot1 == 0 && collisionMagnet == true)
	{
		slot1 = 1; numOfItem++;
	}
	else if (slot1 == 0 && collisionShield == true)
	{
		slot1 = 2; numOfItem++;
	}
	else if (slot2 == 0 && collisionMagnet == true)
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

	//Cheat ! !//
		if (slot1 == 0 && Keyboard::isKeyPressed(Keyboard::Key::LControl) && Keyboard::isKeyPressed(Keyboard::Key::Z))
		{
			slot1 = 1; numOfItem++;
		}
		else if (slot1 == 0 && Keyboard::isKeyPressed(Keyboard::Key::LControl) && Keyboard::isKeyPressed(Keyboard::Key::X))
		{
			slot1 = 2; numOfItem++;
		}
		else if (slot2 == 0 && Keyboard::isKeyPressed(Keyboard::Key::LControl) && Keyboard::isKeyPressed(Keyboard::Key::Z))
		{
			slot2 = 1; numOfItem++;
		}
		else if (slot2 == 0 && Keyboard::isKeyPressed(Keyboard::Key::LControl) && Keyboard::isKeyPressed(Keyboard::Key::X))
		{
			slot2 = 2; numOfItem++;
		}
		else if (slot3 == 0 && Keyboard::isKeyPressed(Keyboard::Key::LControl) && Keyboard::isKeyPressed(Keyboard::Key::Z))
		{
			slot3 = 1; numOfItem++;
		}
		else if (slot3 == 0 && Keyboard::isKeyPressed(Keyboard::Key::LControl) && Keyboard::isKeyPressed(Keyboard::Key::X))
		{
			slot3 = 2; numOfItem++;
		}
		else if (slot4 == 0 && Keyboard::isKeyPressed(Keyboard::Key::LControl) && Keyboard::isKeyPressed(Keyboard::Key::Z))
		{
			slot4 = 1; numOfItem++;
		}
		else if (slot4 == 0 && Keyboard::isKeyPressed(Keyboard::Key::LControl) && Keyboard::isKeyPressed(Keyboard::Key::X))
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
			slot1 = 0;
		}
		if (slot1 == 2)
		{
			useItem = 2;
			useShield = true; numOfItem--;
			slot1 = 0;
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
			slot2 = 0;
		}
		if (slot2 == 2)
		{
			useItem = 2;
			useShield = true; numOfItem--;
			slot2 = 0;
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
			slot3 = 0;
		}
		if (slot3 == 2)
		{
			useItem = 2;
			useShield = true; numOfItem--;
			slot3 = 0;
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
			slot4 = 0;
		}
		if (slot4 == 2)
		{
			useItem = 2;
			useShield = true; numOfItem--;
			slot4 = 0;
		}
	}

	if (useItem == 1 || useItem == 2 )
	{
		//CheckERROR//
		//printf("%d", itemUsing);
		if (itemUsing == 0)
		{
			checkDistance = playerPosition.x + 500;
			itemUsing = 1;
		}
	}
	if (itemUsing == 1 && playerPosition.x >= checkDistance)
	{
		useItem = 0;
		itemUsing = 0;
		useMagnet = false;
		useShield = false;
	}
	if (useItem == 0)
	{
		useMagnet = false;
		useShield = false;
	}

	this->useItem = useItem;
}

void Item::Draw(RenderWindow& window)
{
	window.draw(inventory);
	magnet.Draw(window);
	shield.Draw(window);
}

void Item::Restart()
{
	slot1 = 0;
	slot2 = 0;
	slot3 = 0;
	slot4 = 0;
}
