#include "Enemy.h"

Enemy::Enemy(Texture* texture, Vector2u imageCount, float switchTime, float speed):
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	Texture enemyTexture;
	enemyTexture.loadFromFile("enemyremovebg.png");
	enemy.setTexture(texture);
	enemy.setSize(Vector2f(81.2f,72.0f));
	deltaTime = clock.restart().asSeconds();
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltatime)
{
	if (show == true)
	{
		animation.Update(row, deltatime, 0);
		enemy.setTextureRect(animation.uvRect);
		enemy.move(speed, 0);
	}
	animation.Update(row, deltatime, 0);
	enemy.setTextureRect(animation.uvRect);
}

void Enemy::Draw(RenderWindow& window)
{
	if (show == true)
	{
	window.draw(enemy);
	}
	window.draw(enemy);
}

void Enemy::CheckCollision(FloatRect globleBoundsPlayer)
{
	if (enemy.getGlobalBounds().intersects(globleBoundsPlayer))
	{
		collision = true;
	}
}

void Enemy::UpdatePosition(Vector2f playerPosition, Vector2f playerOrigin)
{
	//CheckERROR//
	//printf("%d", showStatus);
	enemy.setOrigin(playerOrigin);
	int playerPositionint;
	playerPositionint = playerPosition.x;
	if (playerPositionint % 1500 == 0)
	{		
		show = true;
		showStatus = 1;
	}
	if (showStatus == 0)
	{
		enemy.setPosition(0, 0);
	}
	else if (showStatus == 1)
	{
		enemy.setPosition(playerPosition.x + 400, 700);
		showStatus = 2;
	}
	else if (showStatus == 2 && enemy.getPosition().x < playerPosition.x - 400)
	{
		show = false;
		showStatus = 0;
	}
	enemy.setPosition(500, 350);
}
