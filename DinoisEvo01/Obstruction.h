#pragma once
#include <SFML\Graphics.hpp>
#include <windows.h>
using namespace sf;
class Obstruction
{
public:
	Obstruction(Texture* textureOb, Vector2f size, Vector2f position);
	~Obstruction();

	void Draw(RenderWindow& window);
	bool Checkcollision(FloatRect player);

private:
	RectangleShape obstrutction;
	int frequency;
	bool collision = false;
};

