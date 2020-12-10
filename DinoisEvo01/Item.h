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

	//CheckERROR//
	void UpdateInventoryPosition(Vector2f playerPosition);
	void UpdateItemShowPosition(Vector2f playerPosition,FloatRect tokenMeatGlobleBounds ,FloatRect tokenVeggieGlobleBounds, FloatRect ObGlobloBounds, float distance);
	void UpdateItemUsePosition(Vector2f playerPosition, Vector2f playerOrigin);
	void UpdateItemCollectPosition(Vector2f playerPosition);

	void Check(Vector2f playerPosition, int useItem);
	void Draw(RenderWindow& window);
	int Use() { return useItem; };
	void Restart();
private:
	Texture inventoryTexture;
	RectangleShape inventory;

	Magnet magnet;
	Shield shield;

	Vector2f playerPosition;
	float checkDistance;

	int slot1 = 0;
	int slot2 = 0;
	int slot3 = 0;
	int slot4 = 0;

	int useItem = 0;
	int itemUsing = 0;
	bool useMagnet = false;
	bool useShield = false;

	bool collisionMagnet = false;
	bool collisionShield = false;
	
	int numOfItem;
};

