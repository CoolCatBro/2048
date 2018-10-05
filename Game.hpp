#ifndef  _GAME_
#define _GAME_

#include <cstdlib>
#include <ctime>

#include "Level.hpp"

class Game : public Level
{
	int **numgrid;
	int    max;

private:
	void _shiftUp();
	void _shiftLeft();
	void _shiftRight();
	void _shiftDown();

	bool _checkUp();
	bool _checkLeft();
	bool _checkRight();
	bool _checkDown();

	void _generateRandom();

public:
	                   Game();
	void              controls(char ch);
	bool              victory();
	bool              lost();
	void              render();
};


#endif