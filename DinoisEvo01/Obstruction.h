#pragma once
#include <SFML\Graphics.hpp>
#include <windows.h>
using namespace sf;
class Obstruction
{
public:
	Obstruction(Texture* textureOb, Vector2f size, int frequency);
	~Obstruction();

	void Draw(RenderWindow& window);
	bool Checkcollision(FloatRect player);
	void Run(Vector2f playerPosition);
	int Getlife() { return life; };

private:
	RectangleShape obstrutction;
	int frequency;
	int life = 1;
	bool collision = false;
};

