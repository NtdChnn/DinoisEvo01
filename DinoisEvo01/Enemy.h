#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
using namespace sf;
class Enemy
{
public:
	Enemy(Texture* texture, Vector2u imageCount, float switchTime, float speed);
	~Enemy();

	void Update(float deltatime);
	void Draw(RenderWindow& window);
	void CheckCollision(FloatRect globleBoundsPlayer);
	bool Collosion() { return collision; };
	void UpdatePosition(Vector2f playerPosition, Vector2f playerOrigin);
	void Restart();

private:
	RectangleShape enemy;
	Animation animation;
	
	unsigned int row;
	float speed;

	int showStatus = 0;
	bool show = false;
	bool collision = false;

	Clock clock;
};

