#include "Token.h"

Token::Token(int numOfToken, float distance, Texture* tokenTexture01, Texture* tokenTexture02,Vector2f sizeTexture01,Vector2f sizeTexture02) :
	scoretoken(tokenTexture01,tokenTexture02)
{
	this->numOfToken = numOfToken;
	this->distance = distance;

	tokenVeggie.setTexture(tokenTexture01);
	tokenVeggie.setSize(sizeTexture01);
	tokenMeat.setPosition(Vector2f(((distance-100) / numOfToken)+((distance / numOfToken)/2)-250,500.0f));

	tokenMeat.setTexture(tokenTexture02);
	tokenMeat.setSize(sizeTexture02);
	tokenVeggie.setPosition(Vector2f(((distance-100) / numOfToken)-125,500.0f));
}

Token::~Token()
{
}

void Token::Draw(RenderWindow& window)
{
	if (numOfToken > numOfMeat)
	{
		window.draw(tokenMeat);
	}
	if (numOfToken > numOfVeggie)
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
		tokenMeat.setPosition(tokenMeat.getPosition().x, 500);
		tokenMeat.move(Vector2f((distance-100) / numOfToken, 0));
		numOfMeat++;
	}
	if (tokenMeat.getGlobalBounds().intersects(playerGlobleBounds))
	{
		if (collisionMeat == false)
		{
			//Check Error//
			//printf("token meat COLLECT! !");
			collisionMeat = true;
			tokenMeat.setPosition(tokenMeat.getPosition().x, 500);
			tokenMeat.move(Vector2f((distance-100) / numOfToken, 0));
			Meat++;
			numOfMeat++;
			//Check Error//
			//printf("%d", Meat);
		}
	}
	else collisionMeat = false;

	if (playerPosition.x > tokenVeggie.getPosition().x + 550)
	{
		//Check Error//
		//printf("token Veggie MOVE ! !");
		tokenVeggie.setPosition(tokenVeggie.getPosition().x, 500);
		tokenVeggie.move(Vector2f((distance - 50) / numOfToken, 0));
		numOfVeggie++;
	}
	if (tokenVeggie.getGlobalBounds().intersects(playerGlobleBounds))
	{
		if (collisionVeggie == false)
		{
			//Check Error//
			//printf("token Veggie COLLECT! !");
			collisionVeggie = true;
			tokenVeggie.setPosition(tokenVeggie.getPosition().x, 500);
			tokenVeggie.move(Vector2f((distance - 50) / numOfToken, 0));
			Veggie++;
			numOfVeggie++;
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
	if (tokenMeat.getGlobalBounds().intersects(ObGlobleBounds) && magnetMeat == false)
	{
		tokenMeat.move(30, 0);
	}

	if (tokenVeggie.getGlobalBounds().intersects(ObGlobleBounds) && magnetVeggie == false)
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

void Token::Magnet(Vector2f playerposition)
{
	if (tokenMeat.getPosition().x - 250 < (playerposition.x - 350) && (playerposition.x - 350) < tokenMeat.getPosition().x + 400)
	{
		magnetMeat = true;
		if ((tokenMeat.getPosition().x - (playerposition.x - 350)) >= (tokenMeat.getPosition().y - (playerposition.y + 105)))
		{
			if (tokenMeat.getPosition().x - (playerposition.x - 350) > 0)
			{
				tokenMeat.move(-10, 0);
			}
			if (tokenMeat.getPosition().x - (playerposition.x - 350) < 0)
			{
				tokenMeat.move(10, 0);
			}
		}
		if ((tokenMeat.getPosition().x - (playerposition.x - 350)) < (tokenMeat.getPosition().y - (playerposition.y + 105)))
		{
			if (tokenMeat.getPosition().y - (playerposition.y + 105) > 0)
			{
				tokenMeat.move(0, -10);
			}
			if (tokenMeat.getPosition().y - (playerposition.y + 105) < 0)
			{
				tokenMeat.move(0, 10);
			}
		}
	}
	else magnetMeat = false;

	if (tokenVeggie.getPosition().x - 250 < (playerposition.x - 350) && (playerposition.x - 350) < tokenVeggie.getPosition().x + 250)
	{
		magnetVeggie = true;
		if ((tokenVeggie.getPosition().x - (playerposition.x - 350)) >= (tokenVeggie.getPosition().y - (playerposition.y + 105)))
		{
			if (tokenVeggie.getPosition().x - (playerposition.x - 350) > 0)
			{
				tokenVeggie.move(-10, 0);
			}
			if (tokenVeggie.getPosition().x - (playerposition.x - 350) < 0)
			{
				tokenVeggie.move(10, 0);
			}
		}
		if ((tokenVeggie.getPosition().x - (playerposition.x - 350)) < (tokenVeggie.getPosition().y - (playerposition.y + 105)))
		{
			if (tokenVeggie.getPosition().y - (playerposition.y + 105) > 0)
			{
				tokenVeggie.move(0, -10);
			}
			if (tokenVeggie.getPosition().y - (playerposition.y + 105) < 0)
			{
				tokenVeggie.move(0, 10);
			}
		}
	}
	else magnetVeggie = false;
}
