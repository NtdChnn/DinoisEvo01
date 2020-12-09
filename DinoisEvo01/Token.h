#pragma once
#include <SFML\Graphics.hpp>
#include <sstream> 
using namespace sf;
class Token
{
public:
	Token(int numOfToken, float distance);
	~Token();

	bool checkMeat() { return collisionMeat; };
	bool checkVeggie() { return collistionVeggie; };
	int numMeat() { return Meat; };
	int numVeggie() { return Veggie; };
	void Draw(RenderWindow& window);
	void Update(FloatRect playerGlobleBounds);

private:

	int numOfToken;
	float distance;

	Texture meatTexture;
	Texture veggieTexture;

	RectangleShape tokenMeat;
	RectangleShape tokenVeggie;

	int Meat = 0;
	int Veggie = 0;

	bool collisionMeat = false;
	bool collistionVeggie = false;
};

