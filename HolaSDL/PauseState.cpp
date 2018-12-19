#include "PauseState.h"
#include "SDLApplication.h"

PauseState::PauseState(SDLApplication * app) :GameState(app) {
	playButton = new MenuButton(app, app->getTexture(0), 200, 200, 100, 100, onHitPlayButton);
	menuButton = new MenuButton(app, app->getTexture(2), 500, 200, 100, 100, onHitMenuButton);
	gameObjects.push_back(playButton);
	gameObjects.push_back(menuButton);

}
PauseState::~PauseState()
{
}
bool PauseState::handleEvent(SDL_Event & Event) {
	GameState::handleEvent(Event);
	return true;
}

void PauseState::onHitPlayButton(SDLApplication * app) {
	cout << " playState";	
	app->getStateMachine()->changeState(new PlayState(app));
}
void PauseState::onHitMenuButton(SDLApplication * app) {
	cout << "menuState";
	app->getStateMachine()->popState();
}