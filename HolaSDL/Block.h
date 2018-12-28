#pragma once
#include "ArkanoidObject.h"
class Block : public ArkanoidObject
{
private:
	uint row = 0, col = 0;
	uint color = 0;
public:
	Block(uint color, uint ancho, uint alto, Vector2D coord, Texture * textura, uint row, uint col) :
		color(color), ArkanoidObject(ancho, alto, coord, textura), row(row), col(col) {}
	~Block();
	void render() const;
	uint getRow() { return row; }
	uint getCol() { return col; }
	uint getColor() { return color; }
	void update();
	bool handleEvents(SDL_Event& event);
};

