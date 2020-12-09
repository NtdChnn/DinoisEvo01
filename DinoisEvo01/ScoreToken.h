#pragma once
#include <SFML\Graphics.hpp>
#include <sstream> 
using namespace sf;
using namespace std;
class ScoreToken
{
public:
	ScoreToken();
	~ScoreToken();

	void Draw(RenderWindow& window);
	void UpdatPosition(Vector2f playerPosition);
	void UpdateScore(int tokenMeat, int tokenVeggie);
private:
	Font gameFont;

	Texture meatTexture;
	RectangleShape tokenMeat;
	Text tokenMeatScore;
	int scoreMeatToken;
	stringstream meatScoreShow;
	Text tokenMeatX;

	Texture veggieTexture;
	RectangleShape tokenVeggie;
	Text tokenVeggieScore;
	int scoreVeggieToken;
	stringstream veggieScoreShow;
	Text tokenVeggieX;

};

