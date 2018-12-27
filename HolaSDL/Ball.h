#pragma once
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Vector2D.h"
#include "math.h"
#include <iostream>
#include"MovingObject.h"
#include "checkML.h"
#include "PlayState.h"
class Ball : public MovingObject {
private:
	PlayState * game;
public:
	Ball(uint ancho, uint alto, Vector2D coord, Texture * textura, Vector2D vel, PlayState * g) :
		MovingObject(ancho, alto, coord, textura, vel), game(g) {}
	~Ball() { textura = nullptr; }
	void update();
	void resetBall();
	void nuevoNv();
};