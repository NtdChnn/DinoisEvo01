#include <SFML\Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <sstream> 
#include "Stage.h"
#include "Mainmenu.h"
#include "ChooseStage.h"
#include "HowToPlay.h"
#include "Credit.h"
#include "EnterName.h"
#include "LeaderBoard.h"
using namespace sf;
using namespace std;

static const float VIEW_HIGHT = 1000.0f;
static const float VIEW_WIDTH = 700.0f;

int main()
{
	srand(time(NULL));

	Font gameFont;
	gameFont.loadFromFile("PixelEmulator-xq08.ttf");

	//window
	RenderWindow window(VideoMode(1000, 700), "Dino is evo ! !", Style::Close /*| Style::Resize*/);

	//view
	View view(Vector2f(0.0f, 0.0f), Vector2f(VIEW_HIGHT, VIEW_WIDTH));
	View viewCenter(Vector2f(0.0f, 0.0f), Vector2f(VIEW_HIGHT, VIEW_WIDTH));

	//Mainmenu
	Mainmenu mainmenu;

	//ChooseStage
	ChooseStage choosestage;

	//HowToPlay
	HowToPlay howtoplay;

	//Credit
	Credit credit;

	//LeaderBoard
	LeaderBoard leaderboard;

	//EnterName
	EnterName entername(gameFont);

	//TotalScore
	int totalScore = 0;
	int scoreStage00 = 0;
	int scoreStage01 = 0;
	int scoreStage02 = 0;
	int scoreStage03 = 0;
	int scoreStage04 = 0;
	int scoreStage05 = 0;
	int scoreStage06 = 0;

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
		Stage stage00(&playerTexture00, Vector2u(8, 2), Vector2f(117.f, 108.0f), 0.05f, 200.0f, 320.f, 7000, &BG00Texture, &obTexture00, 8, 4, &meatTexture, &veggieTexture, Vector2f(40.0f, 40.0f), Vector2f(40.0f, 40.0f), &enemyTexture00, Vector2u(7, 1), 0.1f, 100.0f);


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
		Stage stage01(&playerTexture01, Vector2u(8, 2), Vector2f(117.0f, 108.0f), 0.05f, 200.0f, 320.f, 9000, &BG01Texture, &obTexture01, 6, 5, &sVeggieTexture, &bVeggieTexture, Vector2f(40.0f, 40.0f), Vector2f(40.0f, 40.0f), &enemyTexture01, Vector2u(7, 1), 0.1f, 100.0f);


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
		Stage stage02(&playerTexture02, Vector2u(8, 2), Vector2f(117.0f, 108.0f), 0.05f, 200.0f, 320.f, 9000, &BG02Texture, &obTexture02, 6, 5, &sMeatTexture, &bMeatTexture, Vector2f(40.0f, 40.0f), Vector2f(40.0f, 40.0f), &enemyTexture02, Vector2u(7, 1), 0.1f, 100.0f);


	//Stage03
		Texture playerTexture03;
		playerTexture03.loadFromFile("player03.png");
		Texture BG03Texture;
		BG03Texture.loadFromFile("BGStage03_USE.png");
		Texture enemyTexture03;
		enemyTexture03.loadFromFile("enemyremovebg.png");
		Texture obTexture03;
		obTexture03.loadFromFile("ObStage03.png"); //&Cactus01texture, Vector2f(89.0f,148.0f), Vector2f(1851.0f,501.0f)
		Stage stage03(&playerTexture03, Vector2u(8, 2), Vector2f(117.0f, 108.0f), 0.05f, 200.0f, 320.f, 12000, &BG03Texture, &obTexture03, 4, 7, &sVeggieTexture, &sVeggieTexture, Vector2f(40.0f, 40.0f), Vector2f(40.0f, 40.0f), &enemyTexture03, Vector2u(7, 1), 0.1f, 100.0f);


	//Stage04
		Texture playerTexture04;
		playerTexture04.loadFromFile("player04.png");
		Texture BG04Texture;
		BG04Texture.loadFromFile("BGStage04_USE.png");
		Texture enemyTexture04;
		enemyTexture04.loadFromFile("enemyremovebg.png");
		Texture obTexture04;
		obTexture04.loadFromFile("ObStage04.png"); //&Cactus01texture, Vector2f(89.0f,148.0f), Vector2f(1851.0f,501.0f)
		Stage stage04(&playerTexture04, Vector2u(8, 2), Vector2f(117.0f, 108.0f), 0.05f, 200.0f, 320.f, 12000, &BG04Texture, &obTexture04, 4, 7, &bVeggieTexture, &bVeggieTexture, Vector2f(40.0f, 40.0f), Vector2f(40.0f, 40.0f), &enemyTexture04, Vector2u(7, 1), 0.1f, 100.0f);


	//Stage05
		Texture playerTexture05;
		playerTexture05.loadFromFile("player05.png");
		Texture BG05Texture;
		BG05Texture.loadFromFile("BGStage05_USE.png");
		Texture enemyTexture05;
		enemyTexture05.loadFromFile("enemyremovebg.png");
		Texture obTexture05;
		obTexture05.loadFromFile("ObStage05.png"); //&Cactus01texture, Vector2f(89.0f,148.0f), Vector2f(1851.0f,501.0f)
		Stage stage05(&playerTexture05, Vector2u(8, 2), Vector2f(117.0f, 108.0f), 0.05f, 200.0f, 320.f, 12000, &BG05Texture, &obTexture05, 4, 7, &sMeatTexture, &sMeatTexture, Vector2f(40.0f, 40.0f), Vector2f(40.0f, 40.0f), &enemyTexture05, Vector2u(7, 1), 0.1f, 100.0f);


	//Stage06
		Texture playerTexture06;
		playerTexture06.loadFromFile("player06.png");
		Texture BG06Texture;
		BG06Texture.loadFromFile("BGStage06_USE.png");
		Texture enemyTexture06;
		enemyTexture06.loadFromFile("enemyremovebg.png");
		Texture obTexture06;
		obTexture06.loadFromFile("ObStage06.png"); //&Cactus01texture, Vector2f(89.0f,148.0f), Vector2f(1851.0f,501.0f)
		Stage stage06(&playerTexture06, Vector2u(8, 2), Vector2f(117.0f, 108.0f), 0.05f, 200.0f, 320.f, 12000, &BG06Texture, &obTexture06, 4, 7, &bMeatTexture, &bMeatTexture, Vector2f(40.0f, 40.0f), Vector2f(40.0f, 40.0f), &enemyTexture06, Vector2u(7, 1), 0.1f, 100.0f);

	//Event
	Event evnt;

	float deltaTime = 0.0f;
	Clock clock;
	window.setFramerateLimit(120);
	viewCenter.setCenter(500, 350);

	int forChangewindow = 99;

	while (window.isOpen())
	{
	//printf("%d ", totalScore);
	//printf("%d  %d\n", mainmenu.GetChangeWindow(), stage00.GetForChangeWindow());
	//printf("%d\n", stage00.GetforTotalScore());
		
		deltaTime = clock.restart().asSeconds();
		mainmenu.Updatemousepos(window);
		if (mainmenu.GetActive() == true)
		{
mainmenu:	mainmenu.Run();
			window.clear();
			window.setView(viewCenter);
			mainmenu.Draw(window);
			window.display();
			if (mainmenu.GetChangeWindow() == 10)
			{
				goto entername;
			}
			else if (mainmenu.GetChangeWindow() == 20)
			{
				goto choosestage;
			}
			else if (mainmenu.GetChangeWindow() == 30)
			{
				goto leaderboard;
			}
			else if (mainmenu.GetChangeWindow() == 40)
			{
				goto howtoplay;
			}
			else if (mainmenu.GetChangeWindow() == 50)
			{
				goto credit;
			}
			else if (mainmenu.GetChangeWindow() == 60)
			{
				window.close();
			}
		} 

		if (choosestage.GetActive() == true)
		{
choosestage:choosestage.Run();
			window.clear();
			window.setView(viewCenter);
			choosestage.UpdateMousePos(window);
			choosestage.Draw(window);
			window.display();
			choosestage.UpdateUnlockStatus00(stage00.GetStageComplete());
			choosestage.UpdateUnlockStatus01(stage01.GetStageComplete());
			choosestage.UpdateUnlockStatus02(stage02.GetStageComplete());
			if (choosestage.GetForChangeWindow() == 0)
			{
				goto stage00;
			} 
			else if (choosestage.GetForChangeWindow() == 1)
			{
				goto stage01;
			}
			else if (choosestage.GetForChangeWindow() == 2)
			{
				goto stage02;
			}
			else if (choosestage.GetForChangeWindow() == 3)
			{
				goto stage03;
			}
			else if (choosestage.GetForChangeWindow() == 4)
			{
				goto stage04;
			}
			else if (choosestage.GetForChangeWindow() == 5)
			{
				goto stage05;
			}
			else if (choosestage.GetForChangeWindow() == 6)
			{
				goto stage06;
			}
			else if (choosestage.GetForChangeWindow() == 99)
			{
				goto mainmenu;
			}
		}

		if (howtoplay.GetActive() == true)
		{
howtoplay:	howtoplay.Run();
			window.clear();
			window.setView(viewCenter);
			howtoplay.Draw(window);
			window.display();
			if (howtoplay.GetforChangeWindow() == 99)
			{
				goto mainmenu;
			}
		}

		if (entername.GetActive() == true)
		{
entername:	entername.Run(window,evnt);
			window.clear();
			window.setView(viewCenter);
			entername.Draw(window);
			window.display();
			if (entername.GetforChangeWindow() == 99)
			{
				goto mainmenu;
			}
			else if (entername.GetforChangeWindow() == 0)
			{
				goto stage00;
			}
		}

		if (leaderboard.GetActive() == true)
		{
leaderboard:	leaderboard.Run();
			window.clear();
			window.setView(viewCenter);
			leaderboard.Draw(window);
			window.display();
			if (leaderboard.GetforChangeWindow() == 99)
			{
				goto mainmenu;
			}
		}

		if (credit.GetActive() == true)
		{
credit:		credit.Run();
			window.clear();
			window.setView(viewCenter);
			credit.Draw(window);
			window.display();
			if (credit.GetforChangeWindow() == 99)
			{
				goto mainmenu;
			}
		}

		if (stage00.GetActive() == true)
		{
stage00:	stage00.run(deltaTime);
			view.setCenter(stage00.Getplayerposition().x, 350.0f);
			window.clear();
			stage00.Draw(window);
			window.setView(view);
			window.display();
			//printf("%d\n", stage00.GetforTotalScore());
			if (stage00.GetForChangeWindow() == 99)
			{
				goto mainmenu;
			}
			else if (stage00.GetForChangeWindow() == 20)
			{
				totalScore += scoreStage00;
				goto choosestage;
			}
			else if (stage00.GetForChangeWindow() == 11 && stage00.GetNextStage() == 1)
			{	
				totalScore += scoreStage00;
				goto stage01;
			} else if (stage00.GetForChangeWindow() == 11 && stage00.GetNextStage() == 2)
			{
				totalScore += scoreStage00;
				goto stage02;
			}
			scoreStage00 = stage00.GetforTotalScore();
		}

		if (stage01.GetActive() == true)
		{
stage01:	stage01.run(deltaTime);
			view.setCenter(stage01.Getplayerposition().x, 350.0f);
			window.clear();
			stage01.Draw(window);
			window.setView(view);
			window.display();
			if (stage01.GetForChangeWindow() == 99)
			{
				goto mainmenu;
			}
			else if (stage01.GetForChangeWindow() == 20)
			{
				totalScore += scoreStage01;
				goto choosestage;
			}
			else if (stage01.GetForChangeWindow() == 11 && stage01.GetNextStage() == 1)
			{
				totalScore += scoreStage01;
				goto stage03;
			} else  if (stage01.GetForChangeWindow() == 11 && stage01.GetNextStage() == 2)
			{
				totalScore += scoreStage01;
				goto stage04;
			}
			scoreStage01 = stage01.GetforTotalScore();
		}

		if (stage02.GetActive() == true)
		{
stage02:	stage02.run(deltaTime);
			view.setCenter(stage02.Getplayerposition().x, 350.0f);
			window.clear();
			stage02.Draw(window);
			window.setView(view);
			window.display();
			if (stage02.GetForChangeWindow() == 99)
			{
				goto mainmenu;
			}
			else if (stage02.GetForChangeWindow() == 20)
			{
				totalScore += scoreStage02;
				goto choosestage;
			}
			else if (stage02.GetForChangeWindow() == 11 && stage02.GetNextStage() == 1)
			{
				totalScore += scoreStage02;
				goto stage05;
			}
			else  if (stage02.GetForChangeWindow() == 11 && stage02.GetNextStage() == 2)
			{
				totalScore += scoreStage02;
				goto stage06;
			}
			scoreStage02 = stage02.GetforTotalScore();
		}

		if (stage03.GetActive() == true)
		{
stage03:	stage03.run(deltaTime);
			view.setCenter(stage03.Getplayerposition().x, 350.0f);
			window.clear();
			stage03.Draw(window);
			window.setView(view);
			window.display();
			if (stage03.GetForChangeWindow() == 99)
			{
				goto mainmenu;
			}
			else if (stage03.GetForChangeWindow() == 20)
			{
				totalScore += scoreStage03;
				goto choosestage;
			}
			else if (stage03.GetForChangeWindow() == 11)
			{
				totalScore += scoreStage03;
				goto mainmenu;
			}
			scoreStage03 = stage03.GetforTotalScore();
		}

		if (stage04.GetActive() == true)
		{
stage04:	stage04.run(deltaTime);
			view.setCenter(stage04.Getplayerposition().x, 350.0f);
			window.clear();
			stage04.Draw(window);
			window.setView(view);
			window.display();
			if (stage04.GetForChangeWindow() == 99)
			{
				goto mainmenu;
			}
			else if (stage04.GetForChangeWindow() == 20)
			{
				totalScore += scoreStage04;
				goto choosestage;
			}
			else if (stage04.GetForChangeWindow() == 11)
			{
				totalScore += scoreStage04;
				goto mainmenu;
			}
			scoreStage04 = stage04.GetforTotalScore();
		}

		if (stage05.GetActive() == true)
		{
stage05:	stage05.run(deltaTime);
			view.setCenter(stage05.Getplayerposition().x, 350.0f);
			window.clear();
			stage05.Draw(window);
			window.setView(view);
			window.display();
			if (stage05.GetForChangeWindow() == 99)
			{
				goto mainmenu;
			}
			else if (stage05.GetForChangeWindow() == 20)
			{
				totalScore += scoreStage05;
				goto choosestage;
			}
			else if (stage05.GetForChangeWindow() == 11)
			{
				totalScore += scoreStage05;
				goto mainmenu;
			}
			scoreStage05 = stage05.GetforTotalScore();
		}
		if (stage06.GetActive() == true)
		{
stage06:	stage06.run(deltaTime);
			view.setCenter(stage06.Getplayerposition().x, 350.0f);
			window.clear();
			stage06.Draw(window);
			window.setView(view);
			window.display();
			if (stage06.GetForChangeWindow() == 99)
			{
				goto mainmenu;
			}
			else if (stage06.GetForChangeWindow() == 20)
			{
				totalScore += scoreStage06;
				goto choosestage;
			}
			else if (stage06.GetForChangeWindow() == 11)
			{
				totalScore += scoreStage06;
				goto mainmenu;
			}
			scoreStage06 = stage06.GetforTotalScore();
		}

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