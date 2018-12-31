#include "EndState.h"
#include "SDLApplication.h"
EndState::EndState(SDLApplication * app):GameState(app) {
	endButton = new MenuButton(app, app->getTexture(3), 300, 200, 150, 150, onHitMenuButton);
	gameObjects.push_back(endButton);
}
EndState::~EndState() {

}
void EndState::onHitMenuButton(SDLApplication * app) {
	cout << " Volviste al Menu";
	app->getStateMachine()->pushState(new MainMenuState(app));
}