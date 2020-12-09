#include "PlayerHitBox.h"
PlayerHitBox::PlayerHitBox(Vector2f size, Vector2f origin)
{
	playerHitBox.setSize(size);
	playerHitBox.setOrigin(origin);
}

PlayerHitBox::~PlayerHitBox()
{
}

void PlayerHitBox::Update(Vector2f playerposition)
{
	playerHitBox.setPosition(playerposition.x+20,playerposition.y+40);
}

void PlayerHitBox::Draw(RenderWindow& window)
{
	window.draw(playerHitBox);
}
