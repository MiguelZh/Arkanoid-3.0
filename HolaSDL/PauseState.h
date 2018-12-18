#pragma once
#include"GameState.h"
#include "MenuButton.h"
class PauseState:public GameState
{
protected:
	MenuButton * pauseButton;
public:
	PauseState(SDLApplication* app) :
		GameState(app){}
	~PauseState();
	void render();
	void update();
	void handleEvent(SDL_Event Event);
};