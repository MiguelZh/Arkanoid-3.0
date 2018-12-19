#pragma once
#include"GameState.h"
#include "MenuButton.h"
class PauseState:public GameState
{
protected:
	MenuButton * playButton;
	MenuButton * menuButton;
public:
	PauseState(SDLApplication* app);
	~PauseState();
	static void onHitPlayButton(SDLApplication * app);
	static void onHitMenuButton(SDLApplication * app);
	bool handleEvent(SDL_Event & Event);
};