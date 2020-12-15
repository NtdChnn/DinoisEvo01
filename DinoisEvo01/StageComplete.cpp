#include "StageComplete.h"

StageComplete::StageComplete()
{
	gameFont.loadFromFile("PixelEmulator-xq08.ttf");
	Color stageCompleteColor(255, 255, 255, 50);
	stageCompleteBG.setFillColor(stageCompleteColor);
	stageCompleteBG.setSize(Vector2f(1000.0f, 700.0f));

	textStage.setFont(gameFont);
	textStage.setOutlineColor(Color::White);
	textStage.setOutlineThickness(5);
	textStage.setFillColor(Color::Black);
	textStage.setStyle(Text::Regular);
	textStage.setString("STAGE");
	textStage.setCharacterSize(100);

	textComplete.setFont(gameFont);
	textComplete.setOutlineColor(Color::White);
	textComplete.setOutlineThickness(5);
	textComplete.setFillColor(Color::Black);
	textComplete.setStyle(Text::Regular);
	textComplete.setString("COMPLETE");
	textComplete.setCharacterSize(100);

	textChooseStage.setFont(gameFont);
	textChooseStage.setOutlineColor(Color::White);
	textChooseStage.setOutlineThickness(2);
	textChooseStage.setFillColor(Color::Black);
	textChooseStage.setStyle(Text::Regular);
	textChooseStage.setString("Choose Stage");
	textChooseStage.setCharacterSize(25);

	textRetry.setFont(gameFont);
	textRetry.setOutlineColor(Color::White);
	textRetry.setOutlineThickness(2);
	textRetry.setFillColor(Color::Black);
	textRetry.setStyle(Text::Regular);
	textRetry.setString("Retry");
	textRetry.setCharacterSize(25);

	textNextStage.setFont(gameFont);
	textNextStage.setOutlineColor(Color::White);
	textNextStage.setOutlineThickness(2);
	textNextStage.setFillColor(Color::Black);
	textNextStage.setStyle(Text::Regular);
	textNextStage.setString("Next Stage");
	textNextStage.setCharacterSize(25);
}

StageComplete::~StageComplete()
{
}

void StageComplete::Draw(RenderWindow& window)
{
	if (stageComplete == true)
	{
		window.draw(stageCompleteBG);
		window.draw(textComplete);
		window.draw(textStage);
		window.draw(textChooseStage);
		window.draw(textRetry);
		window.draw(textNextStage);
	}
}

void StageComplete::Update(float distance, Vector2f playerPosition, int numToken01, int numToken02)
{
	forChangeWindow = 0;
	//printf("UpdateActive\n");
	//printf("%.2f , %.2f", mousePosF.x, mousePosF.y);
	if (mousePos.x >= 120 && mousePos.x <= 350 && mousePos.y <= 605 && mousePos.y >= 545 && stageComplete == true)
	{
		textChooseStage.setOutlineColor(Color::Black);
		Color Gray(125, 130, 122, 255);
		textChooseStage.setFillColor(Gray);
		textChooseStage.setCharacterSize(30);
		textChooseStage.setPosition(textChooseStage.getPosition().x - 30, 600);
		//printf("Collision\n");
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			forChangeWindow = 20;
		}
	}
	else {
		textChooseStage.setOutlineColor(Color::White);
		textChooseStage.setFillColor(Color::Black);
		textChooseStage.setCharacterSize(25);
		textChooseStage.setPosition(playerPosition.x - 380, 600);
	}

	if (mousePos.x >= 500 && mousePos.x <= 600 && mousePos.y <= 605 && mousePos.y >= 545 && stageComplete == true)
	{
		textRetry.setOutlineColor(Color::Black);
		textRetry.setFillColor(Color::Red);
		textRetry.setCharacterSize(30);
		textRetry.setPosition(textRetry.getPosition().x - 20, 600);
		//printf("Collision\n");
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			retry = true;
		}
	}
	else {
		textRetry.setOutlineColor(Color::White);
		textRetry.setFillColor(Color::Black);
		textRetry.setCharacterSize(25);
		textRetry.setPosition(playerPosition.x, 550);
		retry = false;
	}

	if (mousePos.x >= 710 && mousePos.x <= 950 && mousePos.y <= 605 && mousePos.y >= 545 && stageComplete == true)
	{
		textNextStage.setOutlineColor(Color::Black);
		Color Gray(125, 130, 122, 255);
		textNextStage.setFillColor(Gray);
		textNextStage.setCharacterSize(30);
		textNextStage.setPosition(textNextStage.getPosition().x - 40, 600);
		//printf("Collision\n");
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			forChangeWindow = 11;
		}
	}
	else {
		textNextStage.setOutlineColor(Color::White);
		textNextStage.setFillColor(Color::Black);
		textNextStage.setCharacterSize(25);
		textNextStage.setPosition(playerPosition.x + 250, 550);
	}

	if (playerPosition.x >= distance)
	{
		stageComplete = true;
	}
	else stageComplete = false;

	stageCompleteBG.setPosition(playerPosition.x - 500, 0);
	textStage.setPosition(playerPosition.x-200, 200);
	textComplete.setPosition(playerPosition.x-300, 300);
	textChooseStage.setPosition(playerPosition.x - 380, 550);
	textRetry.setPosition(playerPosition.x, 550);
	textNextStage.setPosition(playerPosition.x + 250, 550);
}

void StageComplete::Updatemousepos(RenderWindow& window)
{
	mousePos = Mouse::getPosition(window);
	Vector2f mousePos_F(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	mousePosF = mousePos_F;
}

