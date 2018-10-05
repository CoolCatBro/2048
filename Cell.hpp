#ifndef _CELL_
#define _CELL_

#include "GameManager.hpp"

class Cell : public GameManager
{
	Image *cell;

public:

	int cell_x, cell_y;
	string cellvalue;

public:

	Cell();
	Cell(int x, int y);
	void create( int x, int y);
	int writeCell(string value);
	void render();
};

#endif