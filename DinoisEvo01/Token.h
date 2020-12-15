#pragma once
#include <SFML\Graphics.hpp>
#include <sstream> 
#include "ScoreToken.h"
using namespace sf;
class Token
{
public:
	Token(int numOfToken, float distance, Texture* tokenTexture01, Texture* tokenTexture02, Vector2f sizeTexture01, Vector2f sizeTexture02);
	~Token();

	bool checkMeat() { return collisionMeat; };
	bool checkVeggie() { return collisionVeggie; };
	int numToken01() { return Meat; };
	int numToken02() { return Veggie; };
	void Draw(RenderWindow& window);
	void Update(FloatRect playerGlobleBounds, Vector2f playerPosition);
	void CheckOb(FloatRect ObGlobleBounds);
	void Restart();
	void Magnet(Vector2f playerposition);
	FloatRect GetGlobleBoundsTokenMeat() { return tokenMeat.getGlobalBounds(); };
	FloatRect GetGlobleBoundsTokenVeggie() { return tokenVeggie.getGlobalBounds(); };
	int GetforTotalScore() { return scoretoken.GetTotalScore(); };

private:

	int numOfToken;
	float distance;

	RectangleShape tokenMeat;
	RectangleShape tokenVeggie;

	int Meat = 0;
	int Veggie = 0;
	int numOfMeat = 0;
	int numOfVeggie = 0;

	bool collisionMeat = false;
	bool collisionVeggie = false;
	bool magnetMeat = false;
	bool magnetVeggie = false;

	ScoreToken scoretoken;
};

