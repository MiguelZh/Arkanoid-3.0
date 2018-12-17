#include "MenuButton.h"
bool MenuButton::HandleEvent(SDL_Event& e) {
	if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {    // RATON IZQUIERDO
		SDL_Point p = { e.button.x, e.button.y };
		SDL_Rect r = { x, y, w, h };
		if (SDL_PointInRect(&p, &r)) {
			cb(app);
			handled = true;
		}
		return handled;
	}
}
MenuButton::~MenuButton() {

}