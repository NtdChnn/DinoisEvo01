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

	void Draw(RenderWindow& window);
	void Update(float distance, Vector2f playerPosition, int numToken01 , int numToken02);
	void UpdateForChangeWindow(int windowNow) { this->windowNow = windowNow; };
	bool GetRun() { return stageComplete; };
	int GetForChangeWindow() { return forChangeWindow; };
	void Updatemousepos(RenderWindow& window);
	bool GetRetry() { return retry; };
	
private:
	Font gameFont;

	RectangleShape stageCompleteBG;

	Event evnt;

	Text textStage;
	Text textComplete;

	Text textChooseStage;
	Text textRetry;
	Text textNextStage;

	bool stageComplete = false ;
	bool retry = false;

	int forChangeWindow = 0;
	int windowNow;

	int checkpress01 = 0 ;
	int checkpress02 = 0 ;

	Vector2i mousePos;
	Vector2f mousePosF;
};

