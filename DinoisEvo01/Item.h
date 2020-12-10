#pragma once
#include <SFML\Graphics.hpp>
#include "Shield.h"
#include "Magnet.h"
using namespace sf;
class Item
{
public:
	Item();
	~Item();

	void Update(Vector2f playerPosition	, Vector2f playerOrigin , FloatRect playerGlobleBounds, FloatRect tokenMeatGlobleBounds, FloatRect tokenVeggieGlobleBounds, FloatRect ObGlobleBounds, float distance , int percent);
	void Check(Vector2f playerPosition);
	void Draw(RenderWindow& window);
	int Use() { return useItem; };
private:
	Texture inventoryTexture;
	RectangleShape inventory;

	Magnet magnet;
	Shield shield;

	Vector2f playerPosition;
	float checkDistance;

	int slot1;
	int slot2;
	int slot3;
	int slot4;

	int useItem = 0;
	bool useMagnet = false;
	bool useShield = false;

	bool collisionMagnet = false;
	bool collisionShield = false;
	
	int numOfItem;
};

