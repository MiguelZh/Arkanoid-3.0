#include "MainMenuState.h"
#include "SDLApplication.h"
MainMenuState::MainMenuState(SDLApplication * app): GameState(app){
	playButton = new MenuButton(app,app->getTexture(0), 200, 200, 200, 100, onHitPlayButton);
	gameObjects.push_back(playButton);
}
MainMenuState::~MainMenuState() {
	delete playButton;
	playButton = nullptr;
}
void MainMenuState::onHitPlayButton(SDLApplication * app) {
	cout << " playState";
	app->getStateMachine()->pushState(new PlayState(app));
}
void MainMenuState::update() {

}
void MainMenuState::handleEvents(SDL_Event Event) {
	//nunca entra
	while (SDL_PollEvent(&Event) && !exit) {
		playButton->handleEvents(Event);
	}
}