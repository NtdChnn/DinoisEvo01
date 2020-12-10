#include "Token.h"

Token::Token(int numOfToken, float distance) :
	scoretoken()
{
	this->numOfToken = numOfToken;
	this->distance = distance;

	veggieTexture.loadFromFile("vegetable.png");
	tokenVeggie.setTexture(&veggieTexture);
	tokenVeggie.setSize(Vector2f(40.0f, 40.0f));
	tokenMeat.setPosition(Vector2f(((distance-100) / numOfToken)+((distance / numOfToken)/2)-250,500.0f));

	meatTexture.loadFromFile("meat.png");
	tokenMeat.setTexture(&meatTexture);
	tokenMeat.setSize(Vector2f(40.0f, 40.0f));
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
				tokenMeat.move(-0.2, 0);
			}
			if (tokenMeat.getPosition().x - (playerposition.x - 350) < 0)
			{
				tokenMeat.move(0.2, 0);
			}
		}
		if ((tokenMeat.getPosition().x - (playerposition.x - 350)) < (tokenMeat.getPosition().y - (playerposition.y + 105)))
		{
			if (tokenMeat.getPosition().y - (playerposition.y + 105) > 0)
			{
				tokenMeat.move(0, -0.2);
			}
			if (tokenMeat.getPosition().y - (playerposition.y + 105) < 0)
			{
				tokenMeat.move(0, 0.2);
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
				tokenVeggie.move(-0.2, 0);
			}
			if (tokenVeggie.getPosition().x - (playerposition.x - 350) < 0)
			{
				tokenVeggie.move(0.2, 0);
			}
		}
		if ((tokenVeggie.getPosition().x - (playerposition.x - 350)) < (tokenVeggie.getPosition().y - (playerposition.y + 105)))
		{
			if (tokenVeggie.getPosition().y - (playerposition.y + 105) > 0)
			{
				tokenVeggie.move(0, -0.2);
			}
			if (tokenVeggie.getPosition().y - (playerposition.y + 105) < 0)
			{
				tokenVeggie.move(0, 0.2);
			}
		}
	}
	else magnetVeggie = false;
}
