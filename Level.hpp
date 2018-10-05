#ifndef  _LEVEL_
#define _LEVEL_

#include "Cell.hpp"

class Level
{
protected:

	Cell **grid;

public:
	Level();
	void render();
};

#endif