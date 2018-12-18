#pragma once
#include "GameState.h"
#include "MenuButton.h"
class MainMenuState: public GameState {
protected:
	MenuButton * playButton;
public:
	MainMenuState(SDLApplication * app);
	~MainMenuState();
	static void onHitPlayButton(SDLApplication * app);
	void render();
	void update();
	void handleEvents(SDL_Event  Event);
};