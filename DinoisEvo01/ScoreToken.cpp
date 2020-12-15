#include "ScoreToken.h"

ScoreToken::ScoreToken(Texture* token01Texture,Texture* token02Texture)
{
	gameFont.loadFromFile("PixelEmulator-xq08.ttf");
	token01X.setFont(gameFont);
	token01X.setOutlineColor(Color::White);
	token01X.setOutlineThickness(2);
	token01X.setFillColor(Color::Black);
	token01X.setStyle(Text::Regular);
	token01X.setString("X");
	token01X.setCharacterSize(20);

	token01Score.setFont(gameFont);
	token01Score.setOutlineColor(Color::White);
	token01Score.setOutlineThickness(2);
	token01Score.setFillColor(Color::Black);
	token01Score.setStyle(Text::Regular);
	token01Score.setCharacterSize(20);

	token01.setTexture(token02Texture);
	token01.setSize(Vector2f(40.0f, 40.0f));

	token02X.setFont(gameFont);
	token02X.setOutlineColor(Color::White);
	token02X.setOutlineThickness(2);
	token02X.setFillColor(Color::Black);
	token02X.setStyle(Text::Regular);
	token02X.setString("X");
	token02X.setCharacterSize(20);

	token02Score.setFont(gameFont);
	token02Score.setOutlineColor(Color::White);
	token02Score.setOutlineThickness(2);
	token02Score.setFillColor(Color::Black);
	token02Score.setStyle(Text::Regular);
	token02Score.setCharacterSize(20);

	token02.setTexture(token01Texture);
	token02.setSize(Vector2f(40.0f, 40.0f));

	score.setFont(gameFont);
	score.setOutlineColor(Color::White);
	score.setOutlineThickness(2);
	score.setFillColor(Color::Black);
	score.setStyle(Text::Regular);
	score.setString("Score");
	score.setCharacterSize(20);

	scoreCurrent.setFont(gameFont);
	scoreCurrent.setOutlineColor(Color::White);
	scoreCurrent.setOutlineThickness(2);
	scoreCurrent.setFillColor(Color::Black);
	scoreCurrent.setStyle(Text::Regular);
	scoreCurrent.setCharacterSize(20);
}

ScoreToken::~ScoreToken()
{
}

void ScoreToken::Draw(RenderWindow& window)
{
	window.draw(token01);
	window.draw(token01Score);
	window.draw(token01X);

	window.draw(token02);
	window.draw(token02Score);
	window.draw(token02X);

	window.draw(score);
	window.draw(scoreCurrent);
}

void ScoreToken::UpdatPosition(Vector2f playerPosition)
{
	token01.setPosition(playerPosition.x+300,45.0f);
	token01Score.setPosition(playerPosition.x+400, 50.0f);
	token01X.setPosition(playerPosition.x+360, 50.0f);

	token02.setPosition(playerPosition.x+300, 95.0f);
	token02Score.setPosition(playerPosition.x+400, 100.0f);
	token02X.setPosition(playerPosition.x+360, 100.0f);

	score.setPosition(playerPosition.x + 200, 145.0f);
	scoreCurrent.setPosition(playerPosition.x + 400, 145.0f);
}

void ScoreToken::UpdateScore(int tokenMeat, int tokenVeggie)
{
	//Check ERROR//
	//printf("%d", tokenMeat);
	stringstream meatScoreShow;
	meatScoreShow << tokenMeat;
	token01Score.setString(meatScoreShow.str().c_str());

	//Check ERROR//
	//printf("%d", tokenVeggie);
	stringstream veggieScoreShow;
	veggieScoreShow << tokenVeggie;
	token02Score.setString(veggieScoreShow.str().c_str());

	forTotalScore = (tokenMeat * 20) + (tokenVeggie * 20);

	stringstream scoreShow;
	scoreShow << (tokenVeggie * 20) + (tokenMeat * 20);
	scoreCurrent.setString(scoreShow.str().c_str());
}
