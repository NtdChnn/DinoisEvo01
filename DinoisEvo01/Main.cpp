#include <SFML\Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <sstream> 
#include "Stage.h"
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

	//Stage00
	Texture playerTexture01;
	playerTexture01.loadFromFile("player01.png");
	Texture BG00Texture;
	BG00Texture.loadFromFile("BGStage00_USE.png");
	Texture enemyTexture00;
	enemyTexture00.loadFromFile("enemyremovebg.png");
	Texture obTexture00;
	obTexture00.loadFromFile("ObStage00.png"); //&Cactus01texture, Vector2f(89.0f,148.0f), Vector2f(1851.0f,501.0f)
	Stage stage01(&playerTexture01, Vector2u(8, 2), 0.05f, 200.0f, 320.f, 8000, &BG00Texture, &obTexture00, 5, 7, &enemyTexture00, Vector2u(7, 1), 0.1f, 100.0f);

	//Stage01

	//Stage02
	Texture BG02Texture;
	BG02Texture.loadFromFile("BGStage02_USE.png");

	//Stage03

	//Stage04

	//Stage05

	//Stage06

	//Stage07

	//Stage08

	
	

	

	float deltaTime = 0.0f;
	Clock clock;
	window.setFramerateLimit(120);

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		mainmenu.Updatemousepos(window);

		//CheckERROR//
		//printf("%d", mainmenu.GetChangeWindow());
		switch (mainmenu.GetChangeWindow())
		{
		case 99: /*Main Menu*/
		{
			mainmenu.Run();
			window.clear();
			mainmenu.Draw(window);
			window.display();
			break;
		}
		case 88: /*Story*/
		{
			break;
		}
		case 10: /*Enter Name*/
		{
			break;
		}
		case 20: /*Choose Stage*/
		{
			break;
		}
		case 30: /*LeaderBoard*/
		{
			break;
		}
		case 40: /*HowToPlay*/
		{
			break;
		}
		case 50: /*Credit*/
		{
			break;
		}
		case 0: /*STAGE00*/
		{
			break;
		}
		case 1: /*STAGE01*/
		{
			stage01.run(deltaTime);
			view.setCenter(stage01.Getplayerposition().x, 350.0f);
			window.clear();
			stage01.Draw(window);
			window.setView(view);
			window.display();
			break;
		}
		case 2: /*STAGE02*/
		{
			break;
		}
		case 3: /*STAGE03*/
		{
			break;
		}
		case 4: /*STAGE04*/
		{
			break;
		}
		case 5: /*STAGE05*/
		{
			break;
		}
		case 6: /*STAGE06*/
		{
			break;
		}
		case 7: /*STAGE07*/
		{
			break;
		}
		case 8: /*STAGE08*/
		{
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