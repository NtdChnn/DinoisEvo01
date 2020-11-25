#include "Player.h"


Player::Player(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpSpeed) :
	animation(texture, imageCount, switchTime) , animationJump(texture, imageCount, 0.17f)
{
	this->speed = speed;
	this->jumpSpeed = jumpSpeed;
	row = 0;
	run = false;
	jump = 0;
	body.setSize(Vector2f(117.0f, 108.0f));
	body.setOrigin(350.0f, -105.0f);
	body.setPosition(Vector2f(500.0f, 350.0f));
	body.setTexture(texture);
	deltaTime = clock.restart().asSeconds();
}

Player::~Player()
{
}

void Player::Setintpause(int intpause)
{
	this->intpause = intpause;
}

void Player::Update(float deltatime)
{
	Vector2f movement(0.0f,0.0f);

	if (Keyboard::isKeyPressed(Keyboard::Key::A) && jump == 0 )
	{
		run = true;
		jump = 1;
	}
	if (run == true )
	{
		movement.x += speed * deltatime;
	}
	if (jump == 1 )
	{
		row = 1;
		movement.y -= jumpSpeed * deltatime;
	}
	if (body.getPosition().y <= 150)
	{
		jump = 2;
	}
	if (jump == 2)
	{
		movement.y += jumpSpeed * deltatime;
	}
	if (body.getPosition().y >= 350)
	{
		jump = 0;
		row = 0;
	}
	if (jump == 0 && run == true)
	{
		animation.Update(row, deltatime, 0);
		body.setTextureRect(animation.uvRect);
	} 
	else if(run == true )
	{
		animationJump.Update(1, deltatime , jump);
		body.setTextureRect(animationJump.uvRect);
	}
	else
	{
		body.setTextureRect(animation.uvRect);
	}
	body.move(movement);
}

void Player::Draw(RenderWindow& window)
{
		window.draw(body);
}


