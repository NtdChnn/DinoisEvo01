#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Animation.h"
using namespace sf;
class Player
{
public:
	 Player(Texture* texture, Vector2u imageCount, Vector2f size, float switchTime, float speed, float jumpSpeed);
	~Player();
	
	void Update(float deltatime);
	void Draw(RenderWindow& window);
	Vector2f Getposition() { return body.getPosition(); };
	int Getjump() { return jump; };
	bool Getrun() { return run; };
	FloatRect GetGlobalBounds() { return body.getGlobalBounds(); };
	Vector2f GetOrigin() { return body.getOrigin(); };
	void Restart();
	void Life(int life);
	void UpdateRun(bool run) { this->run = run; };

private:
	RectangleShape body;
	Animation animation;
	Animation animationJump;
	int jump;
	int life;
	unsigned int row;
	bool run;
	float speed;
	float jumpSpeed;
	float deltaTime = 0.0f;
	Clock clock;

	SoundBuffer JumpBuffer;
	Sound JumpSound;
};

