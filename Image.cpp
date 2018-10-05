#include "Image.hpp"

Image :: Image(int sizex, int sizey) :sizex(sizex), sizey(sizey)
{
	index = new int*[sizex*sizey];
	for (int i = 0; i < sizex*sizey; i++)
		index[i] = new int[2];
}

bool Image :: findXY(int x, int y)
{
	for (int i = 0; i < sizex*sizey; i++)
	{
		if (index[i][0] == x && index[i][1] == y)
			return true;
	}
	return false;
}

int Image ::changeChar(int x, int y, char newch)
{
	if (x > sizex|| y > sizey)
		return 0;
	int pos = x + (y - 1) * (sizex + 1) - 1;
	graph[pos] = newch;
	return 1;
}

void Image :: render()
{
	int j = 0;
	for (int i = 0; i < sizex*sizey; i++, j++)
	{
		if (graph[j] == '\n')
			j++;
		if(GameEngine.moveXY(index[i][0], index[i][1]))
		GameEngine.printCh(graph[j]);
	}
}
