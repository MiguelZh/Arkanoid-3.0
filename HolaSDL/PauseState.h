#pragma once
#include"GameState.h"
#include "MenuButton.h"
#include "PlayState.h"
#include "checkML.h"
#include <iostream>
class PauseState:public GameState
{
protected:
	MenuButton * playButton;
	MenuButton * menuButton;
public:
	PauseState(SDLApplication* app);
	~PauseState();
	static void HitPlayButton(SDLApplication * app);
	static void HitMenuButton(SDLApplication * app);
	bool handleEvent(SDL_Event& event);
};