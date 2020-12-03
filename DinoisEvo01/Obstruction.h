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

private:
	RectangleShape obstrutction;
	int frequency;
};

