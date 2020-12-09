#include "Token.h"

Token::Token(int numOfToken, float distance)
{
	this->numOfToken = numOfToken;
	this->distance = distance;

	veggieTexture.loadFromFile("vegetable.png");
	tokenVeggie.setTexture(&veggieTexture);
	tokenVeggie.setSize(Vector2f(40.0f, 40.0f));
	//tokenMeat.setPosition(Vector2f());

	meatTexture.loadFromFile("meat.png");
	tokenMeat.setTexture(&meatTexture);
	tokenMeat.setSize(Vector2f(40.0f, 40.0f));
	//tokenVeggie.setPosition(Vector2f());
}

Token::~Token()
{
}

void Token::Draw(RenderWindow& window)
{
	window.draw(tokenMeat);
	window.draw(tokenVeggie);
}

void Token::Update(FloatRect playerGlobleBounds)
{
	if (tokenMeat.getGlobalBounds().intersects(playerGlobleBounds))
	{
		if (collisionMeat == false)
		{
			collisionMeat = true;
			tokenMeat.move(Vector2f(distance / 14, 0));
			Meat++;
		}
	}
	else collisionMeat = false;

	if (tokenVeggie.getGlobalBounds().intersects(playerGlobleBounds))
	{
		if (collistionVeggie == false)
		{
			collistionVeggie = true;
			tokenVeggie.move(Vector2f(distance / 14, 0));
			Veggie++;
		}
	}
	else collistionVeggie = false;
}