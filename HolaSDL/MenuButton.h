#pragma once
#include"GameObject.h"
#include "Texture.h"
using CallBackOnClick = void(SDLApplication * app);
class MenuButton: public GameObject {
protected:
	CallBackOnClick * cb; SDLApplication * app; uint x, y, w, h; Texture * textura; bool handled; 
public:
	MenuButton(Texture * t,uint x,uint y, uint w, uint h,void (*callBack)(SDLApplication* app)):
		textura(t),x(x),y(y),w(w),h(h),cb(callBack){}
	~MenuButton();
	void update();
	void render();
	void handleEvents(SDL_Event event);
	bool HandleEvent(SDL_Event& e);
};
