#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class PlayerHitBox
{
public:
	PlayerHitBox( Vector2f size , Vector2f origin);
	~PlayerHitBox();

	FloatRect GetGlobalBounds() { return playerHitBox.getGlobalBounds(); };
	void Update(Vector2f playerposition);
	//CheckERROR//
	void Draw(RenderWindow& window);
private:
	RectangleShape playerHitBox; 
};

