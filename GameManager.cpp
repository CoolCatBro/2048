#include <sstream>
#include <fstream>

#include "GameManager.hpp"

using std::stringstream;
using std::ifstream;

GameManager::GameManager()
{
	score = 0;
}


Image* GameManager :: setImage(const string object, int x, int y, int sizex, int sizey)
{
	Image *img = new Image(sizex, sizey);
	updateIndex(img, x, y);
	setGraph(img, object);
	return img;
}


void GameManager :: setGraph(Image* img, const string object)
{
	stringstream buffer;
	ifstream file;
	file.open(object);
	if (!file)
	{
		buffer << object << " " << "not found";
		img->graph = buffer.str();
	}
	buffer << file.rdbuf();
	img->graph = buffer.str();
}

void GameManager::updateIndex(Image* img, int x, int y)
{
	int k = 0;
	for (int i = y; i < y + img->sizey; i++)
	{
		for (int j = x; j < x + img->sizex; j++)
		{
			img->index[k][1] = i;
			img->index[k][0] = j;
			k++;
		}
	}
}

