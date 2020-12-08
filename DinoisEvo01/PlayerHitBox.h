#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class PlayerHitBox
{
public:
	PlayerHitBox( Vector2f size );
	~PlayerHitBox();

	FloatRect GetGlobalBounds() { return playerHitBox.getGlobalBounds(); };
	void Update(Vector2f playerposition);
private:
	RectangleShape playerHitBox; 
};

