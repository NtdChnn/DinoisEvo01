#include "ChooseStage.h"

ChooseStage::ChooseStage()
{
	gameFont.loadFromFile("PixelEmulator-xq08.ttf");

	ChooseStageBGTexture.loadFromFile("BGforChooseStage.png");
	ChooseStageBG.setTexture(&ChooseStageBGTexture);
	ChooseStageBG.setSize(Vector2f(1000, 700));
	ChooseStageBG.setPosition(0, 0);

	stage00BG.setSize(Vector2f(171, 111));
	stage00BG.setPosition(406,199);
	stage00BG.setFillColor(Color::Black);

	stage00Text.setFont(gameFont);
	stage00Text.setOutlineColor(Color::Black);
	stage00Text.setOutlineThickness(2);
	stage00Text.setFillColor(Color::White);
	stage00Text.setStyle(Text::Regular);
	stage00Text.setString("STAGE00");
	stage00Text.setCharacterSize(20);
	stage00Text.setPosition(stage00BG.getPosition().x + 33, stage00BG.getPosition().y + 121);

	stage01BG.setSize(Vector2f(171, 111));
	stage01BG.setPosition(149, 285);
	stage01BG.setFillColor(Color::Black);

	stage01Text.setFont(gameFont);
	stage01Text.setOutlineColor(Color::Black);
	stage01Text.setOutlineThickness(2);
	stage01Text.setFillColor(Color::White);
	stage01Text.setStyle(Text::Regular);
	stage01Text.setString("STAGE01");
	stage01Text.setCharacterSize(20);
	stage01Text.setPosition(stage01BG.getPosition().x + 33, stage01BG.getPosition().y + 110);

	stage01LockText.setFont(gameFont);
	stage01LockText.setOutlineColor(Color::White);
	stage01LockText.setOutlineThickness(2);
	stage01LockText.setFillColor(Color::Black);
	stage01LockText.setStyle(Text::Regular);
	stage01LockText.setString("LOCK");
	stage01LockText.setCharacterSize(20);
	stage01LockText.setPosition(stage01BG.getPosition().x + 50, stage01BG.getPosition().y + 50);

	stage02BG.setSize(Vector2f(171, 111));
	stage02BG.setPosition(656, 285);
	stage02BG.setFillColor(Color::Black);

	stage02Text.setFont(gameFont);
	stage02Text.setOutlineColor(Color::Black);
	stage02Text.setOutlineThickness(2);
	stage02Text.setFillColor(Color::White);
	stage02Text.setStyle(Text::Regular);
	stage02Text.setString("STAGE02");
	stage02Text.setCharacterSize(20);
	stage02Text.setPosition(stage02BG.getPosition().x + 33, stage02BG.getPosition().y + 110);

	stage02LockText.setFont(gameFont);
	stage02LockText.setOutlineColor(Color::White);
	stage02LockText.setOutlineThickness(2);
	stage02LockText.setFillColor(Color::Black);
	stage02LockText.setStyle(Text::Regular);
	stage02LockText.setString("LOCK");
	stage02LockText.setCharacterSize(20);
	stage02LockText.setPosition(stage02BG.getPosition().x + 50, stage02BG.getPosition().y + 50);

	stage03BG.setSize(Vector2f(171, 111));
	stage03BG.setPosition(34, 424);
	stage03BG.setFillColor(Color::Black);

	stage03Text.setFont(gameFont);
	stage03Text.setOutlineColor(Color::Black);
	stage03Text.setOutlineThickness(2);
	stage03Text.setFillColor(Color::White);
	stage03Text.setStyle(Text::Regular);
	stage03Text.setString("STAGE03");
	stage03Text.setCharacterSize(20);
	stage03Text.setPosition(stage03BG.getPosition().x + 33, stage03BG.getPosition().y + 121);

	stage03LockText.setFont(gameFont);
	stage03LockText.setOutlineColor(Color::White);
	stage03LockText.setOutlineThickness(2);
	stage03LockText.setFillColor(Color::Black);
	stage03LockText.setStyle(Text::Regular);
	stage03LockText.setString("LOCK");
	stage03LockText.setCharacterSize(20);
	stage03LockText.setPosition(stage03BG.getPosition().x + 50, stage03BG.getPosition().y + 50);

	stage04BG.setSize(Vector2f(171, 111));
	stage04BG.setPosition(254, 424);
	stage04BG.setFillColor(Color::Black);

	stage04Text.setFont(gameFont);
	stage04Text.setOutlineColor(Color::Black);
	stage04Text.setOutlineThickness(2);
	stage04Text.setFillColor(Color::White);
	stage04Text.setStyle(Text::Regular);
	stage04Text.setString("STAGE04");
	stage04Text.setCharacterSize(20);
	stage04Text.setPosition(stage04BG.getPosition().x + 33, stage04BG.getPosition().y + 121);

	stage04LockText.setFont(gameFont);
	stage04LockText.setOutlineColor(Color::White);
	stage04LockText.setOutlineThickness(2);
	stage04LockText.setFillColor(Color::Black);
	stage04LockText.setStyle(Text::Regular);
	stage04LockText.setString("LOCK");
	stage04LockText.setCharacterSize(20);
	stage04LockText.setPosition(stage04BG.getPosition().x + 50, stage04BG.getPosition().y + 50);

	stage05BG.setSize(Vector2f(171, 111));
	stage05BG.setPosition(540, 424);
	stage05BG.setFillColor(Color::Black);

	stage05Text.setFont(gameFont);
	stage05Text.setOutlineColor(Color::Black);
	stage05Text.setOutlineThickness(2);
	stage05Text.setFillColor(Color::White);
	stage05Text.setStyle(Text::Regular);
	stage05Text.setString("STAGE05");
	stage05Text.setCharacterSize(20);
	stage05Text.setPosition(stage05BG.getPosition().x + 33, stage05BG.getPosition().y + 121);

	stage05LockText.setFont(gameFont);
	stage05LockText.setOutlineColor(Color::White);
	stage05LockText.setOutlineThickness(2);
	stage05LockText.setFillColor(Color::Black);
	stage05LockText.setStyle(Text::Regular);
	stage05LockText.setString("LOCK");
	stage05LockText.setCharacterSize(20);
	stage05LockText.setPosition(stage05BG.getPosition().x + 50, stage05BG.getPosition().y + 50);

	stage06BG.setSize(Vector2f(171, 111));
	stage06BG.setPosition(773, 424);
	stage06BG.setFillColor(Color::Black);

	stage06Text.setFont(gameFont);
	stage06Text.setOutlineColor(Color::Black);
	stage06Text.setOutlineThickness(2);
	stage06Text.setFillColor(Color::White);
	stage06Text.setStyle(Text::Regular);
	stage06Text.setString("STAGE06");
	stage06Text.setCharacterSize(20);
	stage06Text.setPosition(stage06BG.getPosition().x+33, stage06BG.getPosition().y+121);

	stage06LockText.setFont(gameFont);
	stage06LockText.setOutlineColor(Color::White);
	stage06LockText.setOutlineThickness(2);
	stage06LockText.setFillColor(Color::Black);
	stage06LockText.setStyle(Text::Regular);
	stage06LockText.setString("LOCK");
	stage06LockText.setCharacterSize(20);
	stage06LockText.setPosition(stage06BG.getPosition().x + 50, stage06BG.getPosition().y + 50);

	returnToMenuBG.setSize(Vector2f(300, 50));
	returnToMenuBG.setPosition(Vector2f(650, 570));

	returnToMenuText.setFont(gameFont);
	returnToMenuText.setOutlineColor(Color::Black);
	returnToMenuText.setOutlineThickness(2);
	returnToMenuText.setFillColor(Color::White);
	returnToMenuText.setStyle(Text::Regular);
	returnToMenuText.setString("Return To Menu");
	returnToMenuText.setCharacterSize(25);
	returnToMenuText.setOrigin(Vector2f(75, 25));
	returnToMenuText.setPosition(Vector2f(750, 600));
}

ChooseStage::~ChooseStage()
{
}

void ChooseStage::Run()
{
	Active = true;
	forChangeWindow = 10;
	//Stage00
	if (this->stage00BG.getGlobalBounds().contains(mousePosF))
	{
		stage00Text.setOutlineColor(Color::Black);
		Color Gray(125, 130, 122, 255);
		stage00Text.setFillColor(Gray);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			forChangeWindow = 0;
			Active = false;
		}
	}
	else {
		stage00Text.setOutlineColor(Color::Black);
		stage00Text.setFillColor(Color::White);
	}

	//Stage01
	if (this->stage01BG.getGlobalBounds().contains(mousePosF))
	{
		if (stage00statusUnlock == 1 || stage00statusUnlock == 3)
		{
			stage01Text.setOutlineColor(Color::Black);
			Color Gray(125, 130, 122, 255);
			stage01Text.setFillColor(Gray);
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				forChangeWindow = 1;
				Active = false;
			}
		}
	}
	else {
		stage01Text.setOutlineColor(Color::Black);
		stage01Text.setFillColor(Color::White);
	}

	//Stage02
	if (this->stage02BG.getGlobalBounds().contains(mousePosF))
	{
		if (stage00statusUnlock == 2 || stage00statusUnlock == 3)
		{
			stage02Text.setOutlineColor(Color::Black);
			Color Gray(125, 130, 122, 255);
			stage02Text.setFillColor(Gray);
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				forChangeWindow = 2;
				Active = false;
			}
		}
	}
	else {
		stage02Text.setOutlineColor(Color::Black);
		stage02Text.setFillColor(Color::White);
	}

	//Stage03
	if (this->stage03BG.getGlobalBounds().contains(mousePosF))
	{
		if (stage01statusUnlock == 1 || stage01statusUnlock == 3)
		{
			stage03Text.setOutlineColor(Color::Black);
			Color Gray(125, 130, 122, 255);
			stage03Text.setFillColor(Gray);
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				forChangeWindow = 3;
				Active = false;
			}
		}
	}
	else {
		stage03Text.setOutlineColor(Color::Black);
		stage03Text.setFillColor(Color::White);
	}

	//Stage04
	if (this->stage04BG.getGlobalBounds().contains(mousePosF))
	{
		if (stage01statusUnlock == 2 || stage01statusUnlock == 3)
		{
			stage04Text.setOutlineColor(Color::Black);
			Color Gray(125, 130, 122, 255);
			stage04Text.setFillColor(Gray);
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				forChangeWindow = 4;
				Active = false;
			}
		}
	}
	else {
		stage04Text.setOutlineColor(Color::Black);
		stage04Text.setFillColor(Color::White);
	}

	//Stage05
	if (this->stage05BG.getGlobalBounds().contains(mousePosF))
	{
		if (stage02statusUnlock == 1 || stage02statusUnlock == 3)
		{
			stage05Text.setOutlineColor(Color::Black);
			Color Gray(125, 130, 122, 255);
			stage05Text.setFillColor(Gray);
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				forChangeWindow = 5;
				Active = false;
			}
		}
	}
	else {
		stage05Text.setOutlineColor(Color::Black);
		stage05Text.setFillColor(Color::White);
	}

	//Stage06
	if (this->stage06BG.getGlobalBounds().contains(mousePosF))
	{
		if (stage02statusUnlock == 2 || stage02statusUnlock == 3)
		{
			stage06Text.setOutlineColor(Color::Black);
			Color Gray(125, 130, 122, 255);
			stage06Text.setFillColor(Gray);
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				forChangeWindow = 6;
				Active = false;
			}
		}
	}
	else {
		stage06Text.setOutlineColor(Color::Black);
		stage06Text.setFillColor(Color::White);
	}

	//MainMenu//
	if (this->returnToMenuBG.getGlobalBounds().contains(mousePosF))
	{
		returnToMenuText.setOutlineColor(Color::Black);
		returnToMenuText.setFillColor(Color::Red);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			forChangeWindow = 99;
			Active = false;
		}
	}
	else {
		returnToMenuText.setOutlineColor(Color::Black);
		returnToMenuText.setFillColor(Color::White);
	}
}

void ChooseStage::Draw(RenderWindow& window)
{
	window.draw(ChooseStageBG);
	window.draw(stage00Text);
	window.draw(stage01Text);
	window.draw(stage02Text);
	window.draw(stage03Text);
	window.draw(stage04Text);
	window.draw(stage05Text);
	window.draw(stage06Text);
	window.draw(returnToMenuText);

	//window.draw(stage00BG);
	//printf("%d", stage00statusUnlock);
	if (stage00statusUnlock == 2 || stage00statusUnlock == 0)
	{
		window.draw(stage01BG);
		window.draw(stage01LockText);
	}

	if (stage00statusUnlock == 1 || stage00statusUnlock == 0)
	{
		window.draw(stage02BG);
		window.draw(stage02LockText);
	}

	if (stage01statusUnlock == 2 || stage01statusUnlock == 0)
	{
		window.draw(stage03BG);
		window.draw(stage03LockText);
	}

	if (stage01statusUnlock == 1 || stage01statusUnlock == 0)
	{
		window.draw(stage04BG);
		window.draw(stage04LockText);
	}

	if (stage02statusUnlock == 2 || stage02statusUnlock == 0)
	{
		window.draw(stage05BG);
		window.draw(stage05LockText);
	}


	if (stage02statusUnlock == 1 || stage02statusUnlock == 0)
	{
		window.draw(stage06BG);
		window.draw(stage06LockText);
	}

}

void ChooseStage::UpdateMousePos(RenderWindow& window)
{
	mousePos = Mouse::getPosition(window);
	Vector2f mousePos_F(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	mousePosF = mousePos_F;
}
