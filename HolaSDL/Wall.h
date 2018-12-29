#pragma once
#include <iostream>
#include "ArkanoidObject.h"	
class Wall: public ArkanoidObject
{
private:
	string muro;
public:
	Wall(uint ancho, uint alto, Vector2D coord, Texture * textura, string pos) :
		ArkanoidObject(ancho, alto, coord, textura), muro(pos) {}
	bool collides(const SDL_Rect destRect, Vector2D &collVector);
	bool handleEvents(SDL_Event& event);
	~Wall(); 
};

