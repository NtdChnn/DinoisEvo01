#include "Token.h"

Token::Token(int numOfToken, float distance) :
	scoretoken()
{
	this->numOfToken = numOfToken;
	this->distance = distance;

	veggieTexture.loadFromFile("vegetable.png");
	tokenVeggie.setTexture(&veggieTexture);
	tokenVeggie.setSize(Vector2f(40.0f, 40.0f));
	tokenMeat.setPosition(Vector2f(((distance-50) / numOfToken)+((distance / numOfToken)/2)-100,500.0f));

	meatTexture.loadFromFile("meat.png");
	tokenMeat.setTexture(&meatTexture);
	tokenMeat.setSize(Vector2f(40.0f, 40.0f));
	tokenVeggie.setPosition(Vector2f(((distance-50) / numOfToken),500.0f));
}

Token::~Token()
{
}

void Token::Draw(RenderWindow& window)
{
	if (tokenMeat.getPosition().x < distance)
	{
		window.draw(tokenMeat);
	}
	if (tokenVeggie.getPosition().x < distance)
	{
		window.draw(tokenVeggie);
	}
	scoretoken.Draw(window);
}

void Token::Update(FloatRect playerGlobleBounds, Vector2f playerPosition)
{
	if (playerPosition.x > tokenMeat.getPosition().x + 550)
	{
		//Check Error//
		//printf("token meat MOVE ! !");
		tokenMeat.move(Vector2f((distance-50) / numOfToken, 0));
	}
	if (tokenMeat.getGlobalBounds().intersects(playerGlobleBounds))
	{
		if (collisionMeat == false)
		{
			//Check Error//
			//printf("token meat COLLECT! !");
			collisionMeat = true;
			tokenMeat.move(Vector2f((distance-50) / numOfToken, 0));
			Meat++;
			printf("%d", Meat);
		}
	}
	else collisionMeat = false;

	if (playerPosition.x > tokenVeggie.getPosition().x + 550)
	{
		//Check Error//
		//printf("token Veggie MOVE ! !");
		tokenVeggie.move(Vector2f((distance - 50) / numOfToken, 0));
	}
	if (tokenVeggie.getGlobalBounds().intersects(playerGlobleBounds))
	{
		if (collisionVeggie == false)
		{
			//Check Error//
			//printf("token Veggie COLLECT! !");
			collisionVeggie = true;
			tokenVeggie.move(Vector2f((distance - 50) / numOfToken, 0));
			Veggie++;
			//Check Error//
			//printf("%d", Veggie);
		}
	}
	else collisionVeggie = false;

	scoretoken.UpdateScore(Meat, Veggie);
	scoretoken.UpdatPosition(playerPosition);
}

void Token::CheckOb(FloatRect ObGlobleBounds)
{
	if (tokenMeat.getGlobalBounds().intersects(ObGlobleBounds))
	{
		tokenMeat.move(30, 0);
	}

	if (tokenVeggie.getGlobalBounds().intersects(ObGlobleBounds))
	{
		tokenVeggie.move(30, 0);
	}
}

void Token::Restart()
{
	Meat = 0;
	Veggie = 0;
	tokenMeat.setPosition(Vector2f(((distance - 50) / numOfToken) + ((distance / numOfToken) / 2) - 100, 500.0f));
	tokenVeggie.setPosition(Vector2f(((distance - 50) / numOfToken), 500.0f));
}
