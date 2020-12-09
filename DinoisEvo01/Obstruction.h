#pragma once
#include <SFML\Graphics.hpp>
#include <windows.h>
using namespace sf;
class Obstruction
{
public:
	Obstruction(Texture* textureOb, Vector2f size, Vector2f position, int frequency, float distance);
	~Obstruction();

	void Draw(RenderWindow& window);
	bool Checkcollision(FloatRect player);
	void Run(Vector2f playerPosition);
	void UpdateLife(int life);
	int Getlife() { return life; };
	Vector2f GetPosition() { return obstrutction.getPosition(); };
	FloatRect GetGlobleBounds() { return obstrutction.getGlobalBounds(); };
	void Restart();
private:
	Vector2f size;
	Vector2f position;
	RectangleShape obstrutction;
	int frequency;
	int life = 1;
	bool collision = false;
	float distance;
};

