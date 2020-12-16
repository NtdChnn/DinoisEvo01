#define _CRT_SECURE_NO_WARNINGS
#include "LeaderBoard.h"

LeaderBoard::LeaderBoard()
{
	LeaderBoardTexture.loadFromFile("BGforEnterName.png");
	LeaderBoardBG.setTexture(&LeaderBoardTexture);
	LeaderBoardBG.setPosition(0, 0);
	LeaderBoardBG.setSize(Vector2f(1000, 700));

	gameFont.loadFromFile("PixelEmulator-xq08.ttf");

	vector<pair<int, string>> highScore;
	file = fopen("HighScore.txt", "r");
	for (int i = 0; i < 5; i++)
	{
		fscanf(file, "%s", temp);
		nameArr[i] = temp;
		fscanf(file, "%d", &scoreArr[i]);
		highScore.push_back(make_pair(scoreArr[i], nameArr[i]));
	}
	sort(highScore.begin(), highScore.end());
	fclose(file);

	text[0].setFont(gameFont);
	text[0].setPosition(Vector2f(100,300));
	text[0].setString(highScore[0].second);
	text[0].setCharacterSize(25);
	text[0].setOutlineColor(Color::White);

	text[1].setFont(gameFont);
	text[1].setPosition(Vector2f(100, 350));
	text[1].setString(highScore[1].second);
	text[1].setCharacterSize(25);
	text[1].setOutlineColor(Color::White);

	text[2].setFont(gameFont);
	text[2].setPosition(Vector2f(100, 400));
	text[2].setString(highScore[2].second);
	text[2].setCharacterSize(25);
	text[2].setOutlineColor(Color::White);

	text[3].setFont(gameFont);
	text[3].setPosition(Vector2f(100, 450));
	text[3].setString(highScore[3].second);
	text[3].setCharacterSize(25);
	text[3].setOutlineColor(Color::White);

	text[4].setFont(gameFont);
	text[4].setPosition(Vector2f(100, 500));
	text[4].setString(highScore[4].second);
	text[4].setCharacterSize(25);
	text[4].setOutlineColor(Color::White);

	text[5].setFont(gameFont);
	text[5].setPosition(Vector2f(400, 300));
	text[5].setString(to_string(highScore[0].first));
	text[5].setCharacterSize(25);
	text[5].setOutlineColor(Color::White);

	text[6].setFont(gameFont);
	text[6].setPosition(Vector2f(400, 350));
	text[6].setString(to_string(highScore[1].first));
	text[6].setCharacterSize(25);
	text[6].setOutlineColor(Color::White);

	text[7].setFont(gameFont);
	text[7].setPosition(Vector2f(400, 400));
	text[7].setString(to_string(highScore[2].first));
	text[7].setCharacterSize(25);
	text[7].setOutlineColor(Color::White);

	text[8].setFont(gameFont);
	text[8].setPosition(Vector2f(400, 450));
	text[8].setString(to_string(highScore[3].first));
	text[8].setCharacterSize(25);
	text[8].setOutlineColor(Color::White);

	text[9].setFont(gameFont);
	text[9].setPosition(Vector2f(400, 500));
	text[9].setString(to_string(highScore[4].first));
	text[9].setCharacterSize(25);
	text[9].setOutlineColor(Color::White);

	returnToMenuBG.setSize(Vector2f(300, 50));
	returnToMenuBG.setPosition(Vector2f(650, 570));

	returnToMenuText.setFont(gameFont);
	returnToMenuText.setOutlineColor(Color::Black);
	returnToMenuText.setOutlineThickness(2);
	returnToMenuText.setFillColor(Color::White);
	returnToMenuText.setStyle(Text::Regular);
	returnToMenuText.setString("Return To Menu");
	returnToMenuText.setCharacterSize(25);
	returnToMenuText.setOrigin(Vector2f(75, 25));
	returnToMenuText.setPosition(Vector2f(750, 600));
}

LeaderBoard::~LeaderBoard()
{
}

void LeaderBoard::Draw(RenderWindow& window)
{
	mousePos = Mouse::getPosition(window);
	Vector2f mousePos_F(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	mousePosF = mousePos_F;
	window.draw(LeaderBoardBG);
	window.draw(text[0]);
	window.draw(text[1]);
	window.draw(text[2]);
	window.draw(text[3]);
	window.draw(text[4]);
	window.draw(text[5]);
	window.draw(text[6]);
	window.draw(text[7]);
	window.draw(text[8]);
	window.draw(text[9]);
	window.draw(returnToMenuText);
}

void LeaderBoard::Run()
{
	Active = true;
	forChangeWindow = 50;
	//MainMenu//
	if (this->returnToMenuBG.getGlobalBounds().contains(mousePosF))
	{
		returnToMenuText.setOutlineColor(Color::Black);
		returnToMenuText.setFillColor(Color::Red);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			forChangeWindow = 99;
			Active = false;
		}
	}
	else {
		returnToMenuText.setOutlineColor(Color::Black);
		returnToMenuText.setFillColor(Color::White);
	}
}
