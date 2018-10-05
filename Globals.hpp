#ifndef  _GLOBALS_
#define _GLOBALS_

#include <utility>

#include "Engine.hpp"

using std::pair;


extern Engine GameEngine;

extern int timeout;

extern int grid_x;
extern int grid_y;

//IMAGE

extern pair<int, int> cell_size;

//CONTROLS

extern char UP;
extern char LEFT;
extern char RIGHT;
extern char DOWN;

#endif