#pragma once
#include <SFML\Graphics.hpp>
#include <windows.h>
using namespace sf;
class Magnet
{
public:
	Magnet();
	~Magnet();

	void Draw(RenderWindow& window);
	void SetpositionUse(Vector2f playerposition, Vector2f playerorigin, bool use);
	void SetpositionCollect(Vector2f playerposition, int slot1 , int slot2 , int slot3 , int slot4);
	void Check(FloatRect playerGlobleBounds,int numItem);
	int Num() { return numMagnet; };
private:
	Texture magnetTexture;
	RectangleShape magnetpic;
	RectangleShape magnetpic0;
	RectangleShape magnetpic1;
	RectangleShape magnetpic2;
	RectangleShape magnetpic3;
	RectangleShape magnetpic4;

	int slot1 = 0;
	int slot2 = 0;
	int slot3 = 0;
	int slot4 = 0;

	bool use = false;
	bool collision = false;

	int numMagnet = 0;
	int numItem = 0;
};

