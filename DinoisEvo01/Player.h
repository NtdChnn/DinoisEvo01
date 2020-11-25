#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
using namespace sf;
class Player
{
public:
	 Player(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpSpeed);
	~Player();
	
	void Update(float deltatime);
	void Draw(RenderWindow& window);
	Vector2f Getposition() { return body.getPosition(); };
	int Getjump() { return jump; };
	void Setintpause(int intpause);

private:
	RectangleShape body;
	Animation animation;
	Animation animationJump;
	int jump;
	unsigned int row;
	bool run;
	float speed;
	float jumpSpeed;
	float deltaTime = 0.0f;
	Clock clock;
	int intpause;
};

