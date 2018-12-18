#pragma once
#include"GameState.h"
class PauseState:public GameState
{
public:
	PauseState(SDLApplication* app) :
		GameState(app){}
	~PauseState();

private:

};