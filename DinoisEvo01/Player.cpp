#include "Player.h"

Player::Player(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpspeed) :
	animationplayer(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpspeed = jumpspeed;
	row = 0;
	run = false;
	body.setSize(Vector2f(117.0f, 108.0f));
	body.setOrigin(350.0f, -105.0f);
	body.setPosition(Vector2f(500.0f, 350.0f));
	body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float deltatime)
{
	Vector2f movement(0.0f,0.0f);

	if (Keyboard::isKeyPressed(Keyboard::Key::A) )
	{
		run = true;
	}
	if (run == true)
	{
		movement.x += speed * deltatime;
		animationplayer.Update(row, deltatime);
	}

	body.setTextureRect(animationplayer.uvRect);
	body.move(movement);
}

void Player::Draw(RenderWindow& window)
{
	window.draw(body);
}
