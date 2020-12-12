#pragma once
#include <SFML\Graphics.hpp>
#include <windows.h>
#include <sstream> 
using namespace sf;
class StageComplete
{
public:
	StageComplete();
	~StageComplete();

	void Update(float distance, Vector2f playerPosition);
	void UpdateForChangeWindow(int forChangeWindow) { this->forChangeWindow = forChangeWindow; };
	bool Run() { return run; };
	int GetForChangeWindow() { return forChangeWindow; };
private:
	Font gameFont;
	
	Text textStage;
	Text textComplete;

	Text textReturnToMenu;
	Text textReturnToStage;
	Text textNextStage;

	bool run = false;

	int forChangeWindow;
};

