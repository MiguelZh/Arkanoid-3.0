#pragma once
#include"GameObject.h"
#include "Texture.h"
using CallBackOnClick = void(SDLApplication * app);
class MenuButton: public GameObject {
protected:
	CallBackOnClick * cb; SDLApplication * app; uint x, y, w, h; Texture * textura; bool handled; 
public:
	MenuButton(SDLApplication * app,Texture * t,uint x_,uint y_, uint w_, uint h_,void (*callBack)(SDLApplication* app)):
		app(app),textura(t),x(x_),y(y_),w(w_),h(h_),cb(callBack){}
	~MenuButton();
	void update();
	void render();
	bool handleEvents(SDL_Event& e);
};
