#include "Level.hpp"



Level::Level()
{
	grid = new Cell*[grid_y];
	int x = 0;
	int y = 0;

	for (int i = 0; i < grid_y; i++)
	{
		grid[i] = new Cell[grid_x];
		for (int j = 0; j < grid_x; j++)
		{
			grid[i][j].create(x, y);
			x += cell_size.first;
		}
		y += cell_size.second;
		x = 0;
	}
}

void Level::render()
{
	for (int i = 0; i < grid_y; i++)
	{
		for (int j = 0; j < grid_x; j++)
		{;
			grid[i][j].render();
		}
	}
}