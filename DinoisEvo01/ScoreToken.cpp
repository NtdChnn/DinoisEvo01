#include "ScoreToken.h"

ScoreToken::ScoreToken()
{
	gameFont.loadFromFile("PixelEmulator-xq08.ttf");
	tokenMeatX.setFont(gameFont);
	tokenMeatX.setOutlineColor(Color::White);
	tokenMeatX.setOutlineThickness(2);
	tokenMeatX.setFillColor(Color::Black);
	tokenMeatX.setStyle(Text::Regular);
	tokenMeatX.setString("X");
	tokenMeatX.setCharacterSize(20);

	tokenMeatScore.setFont(gameFont);
	tokenMeatScore.setOutlineColor(Color::White);
	tokenMeatScore.setOutlineThickness(2);
	tokenMeatScore.setFillColor(Color::Black);
	tokenMeatScore.setStyle(Text::Regular);
	tokenMeatScore.setCharacterSize(20);

	meatTexture.loadFromFile("meat.png");
	tokenMeat.setTexture(&meatTexture);
	tokenMeat.setSize(Vector2f(40.0f, 40.0f));

	tokenVeggieX.setFont(gameFont);
	tokenVeggieX.setOutlineColor(Color::White);
	tokenVeggieX.setOutlineThickness(2);
	tokenVeggieX.setFillColor(Color::Black);
	tokenVeggieX.setStyle(Text::Regular);
	tokenVeggieX.setString("X");
	tokenVeggieX.setCharacterSize(20);

	tokenVeggieScore.setFont(gameFont);
	tokenVeggieScore.setOutlineColor(Color::White);
	tokenVeggieScore.setOutlineThickness(2);
	tokenVeggieScore.setFillColor(Color::Black);
	tokenVeggieScore.setStyle(Text::Regular);
	tokenVeggieScore.setCharacterSize(20);

	veggieTexture.loadFromFile("vegetable.png");
	tokenVeggie.setTexture(&veggieTexture);
	tokenVeggie.setSize(Vector2f(40.0f, 40.0f));
}

ScoreToken::~ScoreToken()
{
}

void ScoreToken::Draw(RenderWindow& window)
{
	window.draw(tokenMeat);
	window.draw(tokenMeatScore);
	window.draw(tokenMeatX);

	window.draw(tokenVeggie);
	window.draw(tokenVeggieScore);
	window.draw(tokenVeggieX);
}

void ScoreToken::UpdatPosition(Vector2f playerPosition)
{
	tokenMeat.setPosition(playerPosition.x+300,45.0f);
	tokenMeatScore.setPosition(playerPosition.x+400, 50.0f);
	tokenMeatX.setPosition(playerPosition.x+360, 50.0f);

	tokenVeggie.setPosition(playerPosition.x+300, 95.0f);
	tokenVeggieScore.setPosition(playerPosition.x+400, 100.0f);
	tokenVeggieX.setPosition(playerPosition.x+360, 100.0f);
}

void ScoreToken::UpdateScore(int tokenMeat, int tokenVeggie)
{
	//Check ERROR//
	//printf("%d", tokenMeat);
	stringstream meatScoreShow;
	meatScoreShow << tokenMeat;
	tokenMeatScore.setString(meatScoreShow.str().c_str());

	//Check ERROR//
	//printf("%d", tokenVeggie);
	stringstream veggieScoreShow;
	veggieScoreShow << tokenVeggie;
	tokenVeggieScore.setString(veggieScoreShow.str().c_str());
}
