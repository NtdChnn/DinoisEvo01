#include "PlayerHitBox.h"
PlayerHitBox::PlayerHitBox(Vector2f size)
{
	playerHitBox.setSize(size);
}

PlayerHitBox::~PlayerHitBox()
{
}

void PlayerHitBox::Update(Vector2f playerposition)
{
	playerHitBox.setPosition(playerposition);
}
