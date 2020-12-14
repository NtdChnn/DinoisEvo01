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
	Texture playerTexture00;
	playerTexture00.loadFromFile("player00.png");
	Texture BG00Texture;
	BG00Texture.loadFromFile("BGStage00_USE.png");
	Texture enemyTexture00;
	enemyTexture00.loadFromFile("enemyremovebg.png");
	Texture obTexture00;
	obTexture00.loadFromFile("ObStage00.png"); //&Cactus01texture, Vector2f(89.0f,148.0f), Vector2f(1851.0f,501.0f)
	Texture meatTexture;
	meatTexture.loadFromFile("meat.png");
	Texture veggieTexture;
	veggieTexture.loadFromFile("vegetable.png");
	Stage stage00(&playerTexture00, Vector2u(8, 2), Vector2f(117.0f, 108.0f), 0.05f, 200.0f, 320.f, 8000, &BG00Texture, &obTexture00, 5, 7, &meatTexture,&veggieTexture, Vector2f(40.0f, 40.0f), Vector2f(40.0f, 40.0f), &enemyTexture00, Vector2u(7, 1), 0.1f, 100.0f);

	//Stage01
	Texture playerTexture01;
	playerTexture01.loadFromFile("player01.png");
	Texture BG01Texture;
	BG01Texture.loadFromFile("BGStage01_USE.png");
	Texture enemyTexture01;
	enemyTexture01.loadFromFile("enemyremovebg.png");
	Texture sVeggieTexture;
	sVeggieTexture.loadFromFile("small_veggie.png");
	Texture bVeggieTexture;
	bVeggieTexture.loadFromFile("big_veggie.png");
	Texture obTexture01;
	obTexture01.loadFromFile("ObStage01.png"); //&Cactus01texture, Vector2f(89.0f,148.0f), Vector2f(1851.0f,501.0f)
	Stage stage01(&playerTexture01, Vector2u(8, 2), Vector2f(117.0f, 108.0f), 0.05f, 200.0f, 320.f, 8000, &BG01Texture, &obTexture01, 5, 7, &sVeggieTexture, &bVeggieTexture, Vector2f(40.0f, 40.0f), Vector2f(40.0f, 40.0f), &enemyTexture01, Vector2u(7, 1), 0.1f, 100.0f);

	//Stage02
	Texture playerTexture02;
	playerTexture02.loadFromFile("player02.png");
	Texture BG02Texture;
	BG02Texture.loadFromFile("BGStage02_USE.png");
	Texture enemyTexture02;
	enemyTexture02.loadFromFile("enemyremovebg.png");
	Texture sMeatTexture;
	sMeatTexture.loadFromFile("small_meat.png");
	Texture bMeatTexture;
	bMeatTexture.loadFromFile("big_meat.png");
	Texture obTexture02;
	obTexture02.loadFromFile("ObStage02.png"); //&Cactus01texture, Vector2f(89.0f,148.0f), Vector2f(1851.0f,501.0f)
	Stage stage02(&playerTexture02, Vector2u(8, 2),Vector2f(117.0f, 108.0f), 0.05f, 200.0f, 320.f, 8000, &BG02Texture, &obTexture02, 5, 7, &sMeatTexture, &bMeatTexture, Vector2f(40.0f, 40.0f), Vector2f(40.0f, 40.0f), &enemyTexture02, Vector2u(7, 1), 0.1f, 100.0f);

	//Stage03
	Texture playerTexture03;
	playerTexture03.loadFromFile("player03.png");
	Texture BG03Texture;
	BG03Texture.loadFromFile("BGStage03_USE.png");
	Texture enemyTexture03;
	enemyTexture03.loadFromFile("enemyremovebg.png");
	Texture obTexture03;
	obTexture03.loadFromFile("ObStage03.png"); //&Cactus01texture, Vector2f(89.0f,148.0f), Vector2f(1851.0f,501.0f)
	Stage stage03(&playerTexture03, Vector2u(8, 2), Vector2f(117.0f, 108.0f), 0.05f, 200.0f, 320.f, 8000, &BG03Texture, &obTexture03, 5, 7, &sVeggieTexture, &sVeggieTexture, Vector2f(40.0f, 40.0f), Vector2f(40.0f, 40.0f), &enemyTexture03, Vector2u(7, 1), 0.1f, 100.0f);

	//Stage04
	Texture playerTexture04;
	playerTexture04.loadFromFile("player04.png");
	Texture BG04Texture;
	BG04Texture.loadFromFile("BGStage04_USE.png");
	Texture enemyTexture04;
	enemyTexture04.loadFromFile("enemyremovebg.png");
	Texture obTexture04;
	obTexture04.loadFromFile("ObStage04.png"); //&Cactus01texture, Vector2f(89.0f,148.0f), Vector2f(1851.0f,501.0f)
	Stage stage04(&playerTexture04, Vector2u(8, 2), Vector2f(117.0f, 108.0f), 0.05f, 200.0f, 320.f, 8000, &BG04Texture, &obTexture04, 5, 7, &bVeggieTexture, &bVeggieTexture, Vector2f(40.0f, 40.0f), Vector2f(40.0f, 40.0f), &enemyTexture04, Vector2u(7, 1), 0.1f, 100.0f);

	//Stage05
	Texture playerTexture05;
	playerTexture05.loadFromFile("player05.png");
	Texture BG05Texture;
	BG05Texture.loadFromFile("BGStage05_USE.png");
	Texture enemyTexture05;
	enemyTexture05.loadFromFile("enemyremovebg.png");
	Texture obTexture05;
	obTexture05.loadFromFile("ObStage05.png"); //&Cactus01texture, Vector2f(89.0f,148.0f), Vector2f(1851.0f,501.0f)
	Stage stage05(&playerTexture05, Vector2u(8, 2), Vector2f(117.0f, 108.0f), 0.05f, 200.0f, 320.f, 8000, &BG05Texture, &obTexture05, 5, 7, &sMeatTexture, &sMeatTexture, Vector2f(40.0f, 40.0f), Vector2f(40.0f, 40.0f), &enemyTexture05, Vector2u(7, 1), 0.1f, 100.0f);

	//Stage06
	Texture playerTexture06;
	playerTexture06.loadFromFile("player06.png");
	Texture BG06Texture;
	BG06Texture.loadFromFile("BGStage06_USE.png");
	Texture enemyTexture06;
	enemyTexture06.loadFromFile("enemyremovebg.png");
	Texture obTexture06;
	obTexture06.loadFromFile("ObStage06.png"); //&Cactus01texture, Vector2f(89.0f,148.0f), Vector2f(1851.0f,501.0f)
	Stage stage06(&playerTexture06, Vector2u(8, 2), Vector2f(117.0f, 108.0f), 0.05f, 200.0f, 320.f, 8000, &BG06Texture, &obTexture06, 5, 7, &bMeatTexture, &bMeatTexture, Vector2f(40.0f, 40.0f), Vector2f(40.0f, 40.0f), &enemyTexture06, Vector2u(7, 1), 0.1f, 100.0f);

	
	

	

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
			stage00.run(deltaTime);
			view.setCenter(stage01.Getplayerposition().x, 350.0f);
			window.clear();
			stage00.Draw(window);
			window.setView(view);
			window.display();
			break;
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
			stage02.run(deltaTime);
			view.setCenter(stage01.Getplayerposition().x, 350.0f);
			window.clear();
			stage02.Draw(window);
			window.setView(view);
			window.display();
			break;
		}
		case 3: /*STAGE03*/
		{
			stage03.run(deltaTime);
			view.setCenter(stage01.Getplayerposition().x, 350.0f);
			window.clear();
			stage03.Draw(window);
			window.setView(view);
			window.display();
			break;
		}
		case 4: /*STAGE04*/
		{
			stage04.run(deltaTime);
			view.setCenter(stage01.Getplayerposition().x, 350.0f);
			window.clear();
			stage04.Draw(window);
			window.setView(view);
			window.display();
			break;
		}
		case 5: /*STAGE05*/
		{
			stage05.run(deltaTime);
			view.setCenter(stage01.Getplayerposition().x, 350.0f);
			window.clear();
			stage05.Draw(window);
			window.setView(view);
			window.display();
			break;
		}
		case 6: /*STAGE06*/
		{
			stage06.run(deltaTime);
			view.setCenter(stage01.Getplayerposition().x, 350.0f);
			window.clear();
			stage06.Draw(window);
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