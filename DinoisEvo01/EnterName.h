#pragma once
#include "TextBox.h"
#include <iostream>
class EnterName
{
public:
	EnterName(Font font);
	~EnterName();

	void Draw(RenderWindow& window);
	void Run(RenderWindow& window, Event event);
	bool GetActive() { return Active; };
	int GetforChangeWindow() { return forChangeWindow; };
	String GetName() { return name; };
private:
	RectangleShape EnterNameBG;
	Texture EnterNameTexture;

	TextBox textbox;

	String name;
	bool collectHS = false;

	Text returnToMenuText;
	RectangleShape returnToMenuBG;

	Vector2i mousePos;
	Vector2f mousePosF;

	bool Active = false;
	int forChangeWindow = 20;
};

