#include "ScoreToken.h"

ScoreToken::ScoreToken()
{
	gameFont.loadFromFile("PixelEmulator-xq08.ttf");
	tokenMeatX.setFont(gameFont);
	tokenMeatX.setOutlineColor(Color::White);
	tokenMeatX.setFillColor(Color::Black);
	tokenMeatX.setStyle(Text::Regular);
	tokenMeatX.setString("X");
	tokenMeatX.setCharacterSize(20);

	tokenMeatScore.setFont(gameFont);
	tokenMeatScore.setFillColor(Color::White);
	tokenMeatScore.setFillColor(Color::Black);
	tokenMeatScore.setStyle(Text::Regular);
	tokenMeatScore.setCharacterSize(20);

	meatTexture.loadFromFile("meat.png");
	tokenMeat.setTexture(&meatTexture);

	tokenVeggieX.setFont(gameFont);
	tokenVeggieX.setOutlineColor(Color::White);
	tokenVeggieX.setFillColor(Color::Black);
	tokenVeggieX.setStyle(Text::Regular);
	tokenVeggieX.setString("X");
	tokenVeggieX.setCharacterSize(20);

	tokenVeggieScore.setFont(gameFont);
	tokenVeggieScore.setFillColor(Color::White);
	tokenVeggieScore.setFillColor(Color::Black);
	tokenVeggieScore.setStyle(Text::Regular);
	tokenVeggieScore.setCharacterSize(20);

	veggieTexture.loadFromFile("vegetable.png");
	tokenVeggie.setTexture(&veggieTexture);
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
	tokenMeat.setPosition(playerPosition.x+500,50.0f);
	tokenMeatScore.setPosition(playerPosition.x + 580, 50.0f);
	tokenMeatX.setPosition(playerPosition.x + 540, 50.0f);

	tokenVeggie.setPosition(playerPosition.x + 500, 50.0f);
	tokenVeggieScore.setPosition(playerPosition.x + 580, 50.0f);
	tokenVeggieX.setPosition(playerPosition.x + 540, 50.0f);
}

void ScoreToken::UpdateScore(int tokenMeat, int tokenVeggie)
{
	meatScoreShow << tokenMeat;
	tokenMeatScore.setString(meatScoreShow.str().c_str());

	veggieScoreShow << tokenVeggie;
	tokenVeggieScore.setString(veggieScoreShow.str().c_str());
}
