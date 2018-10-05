#ifndef  _GAMEMANAGER_
#define _GAMEMANAGER_

#include <vector>
#include <utility>

#include "Image.hpp"
#include "Globals.hpp"

using std::vector;
using std::pair;


class GameManager 
{
protected:
	int score;

public:
	GameManager();
	 Image* setImage     (const string,int x,int y,int sizex,int sizey);
     void  setGraph        (Image*,const string);
     void  updateIndex    (Image*,int x,int y);
};

#endif
