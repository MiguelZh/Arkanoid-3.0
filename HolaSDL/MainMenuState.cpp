#include "MainMenuState.h"
#include "SDLApplication.h"
MainMenuState::MainMenuState(SDLApplication * app): GameState(app){
	playButton = new MenuButton(app,app->getTexture(0), 100, 200, 200, 100, onHitPlayButton);
	loadButton = new MenuButton(app, app->getTexture(10), 500, 200, 200, 100, onHitLoadButton);
	gameObjects.push_back(playButton);
	gameObjects.push_back(loadButton);
}
MainMenuState::~MainMenuState() {
	delete playButton;
	playButton = nullptr;
	app = nullptr;
}
void MainMenuState::onHitPlayButton(SDLApplication * app) {
	cout << " playState";
	app->getStateMachine()->pushState(new PlayState(app));
}
void MainMenuState::onHitLoadButton(SDLApplication * app) {
	cout << " loadState";
	cout << " nombre del archivo que quiere cargar: " << endl;
	string filename;
	cin >> filename;
	app->getStateMachine()->pushState(new PlayState(app,filename));
}
void MainMenuState::update() {

}
bool MainMenuState::handleEvent(SDL_Event& event) {
	bool handled = false;
	if (loadButton->handleEvents(event)) {
		handled = true;
	}
	GameState::handleEvent(event);
	return handled;
}