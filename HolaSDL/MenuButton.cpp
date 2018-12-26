#include "MenuButton.h"
#include "checkML.h"
#include <iostream>
bool MenuButton::handleEvents(SDL_Event& e) {
	if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) { // RATON IZQUIERDO
		SDL_Point p = { e.button.x, e.button.y };
		SDL_Rect r = { x, y, w, h };
		if (SDL_PointInRect(&p, &r)) {
			cb(app);
			handled = true;
		}		
	}
	return handled;
}
MenuButton::~MenuButton() {
	cb = nullptr;
	app = nullptr;
	textura = nullptr;
}
void MenuButton::render() {
	SDL_Rect destrect;
	destrect.x = x;
	destrect.y = y;
	destrect.w = w;
	destrect.h = h;
	textura->render(destrect, SDL_FLIP_NONE);
}
void MenuButton::update() {

}