#pragma once
#include "MovingObject.h"
class Paddle :public MovingObject
{
private:
	SDL_Event E; uint width = 0;
public:
	Paddle(int ancho, int alto, Vector2D coord, Texture * textura, Vector2D vel) :
		MovingObject(ancho, alto, coord, textura, vel) {
	}
	~Paddle();
	void modificaPos(int num, bool dir);
	bool handleEvents(SDL_Event &E);
	bool collides(const SDL_Rect destRect, Vector2D &collVector);
	Vector2D ballhitPaddle(const SDL_Rect * ballrect);
};

