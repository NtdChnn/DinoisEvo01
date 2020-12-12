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

private:
	Font gameFont;
	
	Text textStage;
	Text textComplete;
};

