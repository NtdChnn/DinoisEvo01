#include <SFML\Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <sstream> 
#include "Player.h"
using namespace sf;
using namespace std;

static const float VIEW_HIGHT = 1000.0f;
static const float VIEW_WIDTH = 700.0f;

int main()
{
	srand(time(NULL));

	RenderWindow window(VideoMode(1000, 700), "Dino is evo ! !", Style::Close /*| Style::Resize*/);
	
	//view
	View view(Vector2f(0.0f, 0.0f), Vector2f(VIEW_HIGHT, VIEW_WIDTH));
	
	//BG
	RectangleShape BG01(Vector2f(7260, 700));
	BG01.setPosition(Vector2f(0.0f, 0.0f));

	//setTexture
	Texture playerTextureRun;
	playerTextureRun.loadFromFile("player01Run.png");
	Texture BG01Texture;
	BG01Texture.loadFromFile("BGForestNight.png");
	BG01.setTexture(&BG01Texture);

	Player player(&playerTextureRun, Vector2u(8, 1), 0.05f,200.0f,300.0f);

	float deltaTime = 0.0f;
	Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		player.Update(deltaTime);

		view.setCenter(player.Getpositionx().x, 350.0f);

		window.clear();
		window.draw(BG01);
		player.Draw(window);
		window.setView(view);
		window.display();

		Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case Event::Closed:
				window.close();
				break;
			}

		}
	}

	return 0;
}