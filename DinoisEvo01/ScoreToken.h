#pragma once
#include <SFML\Graphics.hpp>
#include <sstream> 
using namespace sf;
using namespace std;
class ScoreToken
{
public:
	ScoreToken(Texture* token01Texture, Texture* token02Texture);
	~ScoreToken();

	void Draw(RenderWindow& window);
	void UpdatPosition(Vector2f playerPosition);
	void UpdateScore(int tokenMeat, int tokenVeggie);
	int GetTotalScore() { return forTotalScore; };
private:
	Font gameFont;

	Texture meatTexture;
	RectangleShape token01;
	Text token01Score;
	int scoreMeatToken;
	Text token01X;

	Texture veggieTexture;
	RectangleShape token02;
	Text token02Score;
	int scoreVeggieToken;
	Text token02X;

	int forTotalScore = 0;
	Text score;
	Text scoreCurrent;

};