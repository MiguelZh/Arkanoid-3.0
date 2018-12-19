#include "PauseState.h"
#include "SDLApplication.h"
PauseState::PauseState(SDLApplication * app) :GameState(app) {
	playButton = new MenuButton(app, app->getTexture(0), 100, 200, 100, 100, onHitPlayButton);
	menuBotton = new MenuButton(app, app->getTexture(2), 400, 100, 100, 300, onHitMenuButton);
	gameObjects.push_back(playButton);
	gameObjects.push_back(menuBotton);

}
PauseState::~PauseState()
{
}
bool PauseState::handleEvent(SDL_Event& Event) {
	return true;
}
void PauseState::onHitPlayButton(SDLApplication * app) {
	cout << " playState";
	app->getStateMachine()->popState();
}
void PauseState::onHitMenuButton(SDLApplication * app) {
	cout << "menuState";
	app->getStateMachine()->changeState(new MainMenuState(app));
}