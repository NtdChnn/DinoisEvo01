#include <SFML\Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <sstream> 
#include "Stage.h"
#include "Player.h"
#include "Mainmenu.h"
using namespace sf;
using namespace std;

static const float VIEW_HIGHT = 1000.0f;
static const float VIEW_WIDTH = 700.0f;

int main()
{
	srand(time(NULL));

	//window
	RenderWindow window(VideoMode(1000, 700), "Dino is evo ! !", Style::Close /*| Style::Resize*/);

	//view
	View view(Vector2f(0.0f, 0.0f), Vector2f(VIEW_HIGHT, VIEW_WIDTH));

	//Mainmenu
	Mainmenu mainmenu;

	//Stage01
	Texture playerTexture01;
	playerTexture01.loadFromFile("player01.png");
	Texture BG01Texture;
	BG01Texture.loadFromFile("BGdesert.png");
	//&Rock02texture, Vector2f(177.0f,56.0f), Vector2f(1851.0f,501.0f)
	Texture Rocktexture;
	Rocktexture.loadFromFile("rockrealrockremoveBG.png");
	//&Cactus01texture, Vector2f(89.0f,148.0f), Vector2f(1851.0f,501.0f)
	Texture Cactus01Texture;
	Cactus01Texture.loadFromFile("cactus01-removebg.png");
	Stage stage01(&playerTexture01 , Vector2u(8, 2), 0.05f, 200.0f,320.f, 8000, &BG01Texture,&Cactus01Texture,5,7);

	float deltaTime = 0.0f;
	Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		mainmenu.Updatemousepos(window);

		//CheckERROR//
		//printf("%d", mainmenu.GetChangeWindow());
		switch (mainmenu.GetChangeWindow())
		{
		case 0:
		{
			mainmenu.Run();
			window.clear();
			mainmenu.Draw(window);
			window.display();
			break;
		}
		case 1:
		{
			stage01.run(deltaTime);
			view.setCenter(stage01.Getplayerposition().x, 350.0f);
			window.clear();
			stage01.Draw(window);
			window.setView(view);
			window.display();
			break;
		}
		}
		

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