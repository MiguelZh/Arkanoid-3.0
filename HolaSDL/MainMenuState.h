#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "PlayState.h"
class MainMenuState: public GameState {
protected:
	MenuButton * playButton;
	MenuButton * loadButton;
public:
	MainMenuState(SDLApplication * app);
	~MainMenuState();
	static void onHitPlayButton(SDLApplication * app);
	static void onHitLoadButton(SDLApplication * app);
	void update();
	bool handleEvent(SDL_Event& event);
};