#pragma once
#include <SFML\Graphics.hpp>
#include <windows.h>
using namespace sf;
class Shield
{
public:
	Shield();
	~Shield();

	void Draw(RenderWindow& window);
	void SetpositionUse(Vector2f playerposition, Vector2f playerorigin, bool use);
	void SetpositionCollect(Vector2f playerposition, int slot1, int slot2, int slot3, int slot4);
	void SetpositionShow(Vector2f playerposition, FloatRect globleBoundsMeat, FloatRect globleBoundsVeggie, FloatRect globleBoundsOb, float distance);
	void Check(FloatRect playerGlobleBounds, int numItem);
	void Random(int percent);
	FloatRect GetGlobleBounds() { return shieldpic.getGlobalBounds(); };
	int Num() { return numShield; };
	bool Collision() { return collision; };
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
	bool show = false;

	int numShield = 0;
	int numItem = 0;

	int checkshow = 0;

	float distance;

	int checkrand = 0;
};

