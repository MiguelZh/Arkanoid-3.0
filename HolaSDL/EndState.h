#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "MainMenuState.h"
class EndState: public GameState {
protected:
	MenuButton * endButton;
public:
	EndState(SDLApplication * app);
	
	//bool handleEvent(SDL_Event& Event);
	static void onHitMenuButton(SDLApplication * app);
	~EndState();
};