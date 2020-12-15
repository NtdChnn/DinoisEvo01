#pragma once
#include <SFML\Graphics.hpp>
#include <sstream> 
using namespace sf;
class ChooseStage
{
public:
	ChooseStage();
	~ChooseStage();

	void Run();
	void Draw(RenderWindow& window);
	void UpdateMousePos(RenderWindow& window);
	bool GetActive() { return Active; };
	int GetForChangeWindow() { return forChangeWindow; };
	void UpdateUnlockStatus00(int stage00stagecomplete) { this->stage00statusUnlock = stage00stagecomplete; };
	void UpdateUnlockStatus01(int stage01stagecomplete) { this->stage01statusUnlock = stage01stagecomplete; };
	void UpdateUnlockStatus02(int stage02stagecomplete) { this->stage02statusUnlock = stage02stagecomplete; };
private:
	RectangleShape ChooseStageBG;
	RectangleShape stage00BG;
	RectangleShape stage01BG;
	RectangleShape stage02BG;
	RectangleShape stage03BG;
	RectangleShape stage04BG;
	RectangleShape stage05BG;
	RectangleShape stage06BG;
	
	Text returnToMenuText;
	RectangleShape returnToMenuBG;

	Texture ChooseStageBGTexture;

	bool Active = false;
	int forChangeWindow = 10;

	Font gameFont;

	Text stage00Text;
	Text stage01Text;
	Text stage01LockText;
	Text stage02Text;
	Text stage02LockText;
	Text stage03Text;
	Text stage03LockText;
	Text stage04Text;
	Text stage04LockText;
	Text stage05Text;
	Text stage05LockText;
	Text stage06Text;
	Text stage06LockText;

	Vector2i mousePos;
	Vector2f mousePosF;

	int stage00statusUnlock = 0;
	int stage01statusUnlock = 0;
	int stage02statusUnlock = 0;
};

