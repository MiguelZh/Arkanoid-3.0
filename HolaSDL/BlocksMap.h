#pragma once
#include "ArkanoidObject.h"
#include "Block.h"
class PlayState;
class BlocksMap: public ArkanoidObject
{
private:
	Block *** blocks = nullptr;
	uint numBloques, puntos = 0, puntosAnt = 0;
	int fila = 0, columna = 0;
public:
	BlocksMap(uint w, uint h, Texture * t) :
		ArkanoidObject(w, h, { 0,0 }, t) {}
	~BlocksMap();
	void LeerFichero(string filename, bool load);
	void render();
	bool handleEvents(SDL_Event& event);
	bool detectCollision(const SDL_Rect destRect, Vector2D &collVector, const Vector2D &vel, PlayState * p);
	Block* BlocksMap::collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector);
	Block* BlocksMap::blockAt(const Vector2D& p);
	void ballHitBlock(Block * bloque);
	bool pasoNivel();
	void puntuacion();
	int bloqueConcreto(int row, int col);
	uint getFilas() { return fila; }
	uint getColumnas() { return columna; }
};

