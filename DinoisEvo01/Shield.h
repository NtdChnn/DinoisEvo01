#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class Shield
{
public:
	Shield();
	~Shield();

	void Draw(RenderWindow& window);
	void SetpositionUse(Vector2f playerposition, Vector2f playerorigin, bool use);
	void SetpositionCollect(Vector2f playerposition, int slot1, int slot2, int slot3, int slot4);
	void Check(FloatRect playerGlobleBounds, int numItem);
	int Num() { return numShield; };
private:
	Texture shieldTexture;
	RectangleShape shieldpic;
	RectangleShape shieldpic0;
	RectangleShape shieldpic1;
	RectangleShape shieldpic2;
	RectangleShape shieldpic3;
	RectangleShape shieldpic4;

	int slot1 = 0;
	int slot2 = 0;
	int slot3 = 0;
	int slot4 = 0;

	bool use = false;
	bool collision = false;

	int numShield = 0;
	int numItem = 0;
};

