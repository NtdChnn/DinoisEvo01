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
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltatime)
{
	Vector2f movement(0.0, 0.0);
	if (showStatus == 2)
	{
		movement.x -= deltatime * speed;
	}
	else 
	{
		movement.x = 0;
	}
	enemy.move(movement);
	animation.Update(row, deltatime, 0);
	enemy.setTextureRect(animation.uvRect);
}

void Enemy::Draw(RenderWindow& window)
{
	if (show == true)
	{
	window.draw(enemy);
	}
	//ChecK ERROR//
	//printf("Draw Enemy\n");
	window.draw(enemy);
}

void Enemy::CheckCollision(FloatRect globleBoundsPlayer)
{
	if (enemy.getGlobalBounds().intersects(globleBoundsPlayer))
	{
		collision = true;
	}
	else collision = false;
}

void Enemy::UpdatePosition(Vector2f playerPosition, Vector2f playerOrigin)
{
	//CheckERROR//
	//printf("%d", showStatus);
	//printf("%.2f %.2f \n", enemy.getPosition().x, enemy.getPosition().y);
	enemy.setOrigin(playerOrigin);
	int playerPositionint;
	playerPositionint = playerPosition.x;
	if (playerPositionint % 1500 <= 100 && show == false)
	{		
		show = true;
		showStatus = 1;
	}
	if (showStatus == 0)
	{
		enemy.setPosition(0, 0);
	}
	if (showStatus == 1)
	{
		enemy.setPosition(playerPosition.x + 1000, 250);
		showStatus = 2;
	}
	if (showStatus == 2 && enemy.getPosition().x < playerPosition.x - 400)
	{
		show = false;
		showStatus = 0;
	}
	//enemy.setPosition(500, 300);
}

void Enemy::Restart()
{
	showStatus = 0;
	collision = false;
}
