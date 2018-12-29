#include "Paddle.h"
#include "PlayState.h"
Paddle::~Paddle()
{
	textura = nullptr;
}
bool Paddle::handleEvents(SDL_Event &E) {
	bool handled = false;
	if (E.type == SDL_KEYDOWN) {
		switch (E.key.keysym.sym)
		{
		case SDLK_RIGHT:
			modificaPos(20, true);
			handled = true;
			break;
		case SDLK_LEFT:
			modificaPos(20, false);
			handled = true;
			break;
		default: modificaPos(0, true);
			break;
		}
	}
	return handled;
	/*
	velocidad = {0,0};
	 if (E.type == SDL_KEYDOWN) {
		switch (E.key.keysym.sym)
		{
		case SDLK_RIGHT:
			 velocidad = {4,0 };
			break;
		case SDLK_LEFT:
			 velocidad = {-4,0 };
		}
	}
	 if (E.type == SDL_KEYUP) {
		switch (E.key.keysym.sym)
		{
		default:velocidad = {0,0};
			break;
		}
	}
	*/
}
void Paddle::modificaPos(int num, bool dir) {
	velocidad = { (double)num,0 };
	if (dir &&coord.getX() < 710)
	{
		coord = coord + velocidad;
	}
	else if (!dir &&coord.getX() > 10) {
		coord = coord - velocidad;
	}
	else  coord = coord;
	/*
	if(coord.getX() >20 && coord.getX() < 780){
	   coord = coord + velocidad; // bug, no se sabe el porque
	}
	*/
}
bool Paddle::collides(const SDL_Rect destRect, Vector2D &collVector) {
	if (SDL_HasIntersection(&destRect, &getRect())) {
		collVector = ballhitPaddle(&destRect);
		return true;
	}
	else return false;
}
Vector2D Paddle::ballhitPaddle(const SDL_Rect * ballrect) {
	Vector2D vectorCol;
	uint BallCenter = ballrect->x + (ballrect->w / 2);
	uint parte = getW() / 6; // paddle dividido en 6 trozos
	if (BallCenter > coord.getX() && BallCenter < coord.getX() + parte) { // 1/6 del paddle izquierda
		vectorCol = Vector2D(4, 10);
	}
	if (BallCenter > coord.getX() + parte && BallCenter < coord.getX() + parte * 2) {
		vectorCol = Vector2D(2, 10);
	}
	if (BallCenter > coord.getX() + parte * 2 && BallCenter < coord.getX() + parte * 4) { // el doble porque cuenta la 
		vectorCol = Vector2D(0, 10);													   //mitad izq y derecha del paddle
	}
	if (BallCenter > coord.getX() + parte * 4 && BallCenter < coord.getX() + parte * 5) { // 5/6 derecha
		vectorCol = Vector2D(-2, 10);
	}
	if (BallCenter > coord.getX() + parte * 5 && BallCenter < coord.getX() + getW()) {
		vectorCol = Vector2D(-4, 10);
	}
	vectorCol.normalize();
	return vectorCol;
}
