#ifndef  _IMAGE_
#define _IMAGE_

#include "Engine.hpp"

class GameManager;

class Image
{
	string graph;
	int** index;
	int sizex;
	int sizey;

public:
	Image() {};
	Image(int sizex, int sizey);
	bool findXY(int x, int y);
	int changeChar(int x, int y, char newch);
	void render();
	friend class GameManager;
};

#endif