#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "PlayState.h"
class MainMenuState: public GameState {
protected:
	MenuButton * playButton;
public:
	MainMenuState(SDLApplication * app);
	virtual ~MainMenuState();
	static void onHitPlayButton(SDLApplication * app);
	void update();
	void handleEvents(SDL_Event  Event);
};