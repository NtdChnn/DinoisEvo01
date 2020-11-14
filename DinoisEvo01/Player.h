#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
using namespace sf;
class Player
{
public:
	 Player(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpspeed);
	~Player();
	
	void Update(float deltatime);
	void Draw(RenderWindow& window);
	Vector2f Getposition() { return body.getPosition(); };

private:
	RectangleShape body;
	Animation animation;
	unsigned int row;
	bool run;
	int jump;
	float speed;
	float jumpspeed;
};

