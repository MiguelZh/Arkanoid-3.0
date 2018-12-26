#include "PauseState.h"
#include "SDLApplication.h"

PauseState::PauseState(SDLApplication * app) :GameState(app) {
	playButton = new MenuButton(app, app->getTexture(0), 200, 200, 100, 100, HitPlayButton);
	menuButton = new MenuButton(app, app->getTexture(3), 500, 200, 100, 100, HitMenuButton);
	gameObjects.push_back(playButton);
	gameObjects.push_back(menuButton);

}
PauseState::~PauseState()
{
	delete playButton;
	playButton = nullptr;
	delete menuButton;
	menuButton = nullptr;
}

void PauseState::HitPlayButton(SDLApplication * app) {
	cout << " playState";	
	app->getStateMachine()->popState();
}
void PauseState::HitMenuButton(SDLApplication * app) {
	cout << " menuState";
	app->getStateMachine()->pushState(new MainMenuState(app));
}
bool PauseState::handleEvent(SDL_Event& event) {
	bool handled = false;
	if (menuButton->handleEvents(event)) {
		handled = true;
	}
	GameState::handleEvent(event);	
	return handled;
}