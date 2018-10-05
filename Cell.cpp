#include "Cell.hpp"

Cell::Cell()
{
	cell_x = 0;
	cell_y = 0;
}

Cell :: Cell(int x, int y)
{
	create(x, y);
}

int Cell :: writeCell(string value)
{
	cellvalue = value;
	int x = 3, y = 2;
	for (int i = 0; i < cellvalue.size(); i++)
	{
		if (cell->changeChar(x, y, cellvalue[i]))
			x++;
		else
			return 0;
	}
	return 1;
}

void Cell::create(int x, int y)
{
	cell_x = x;
	cell_y = y;
	cell = setImage("cell.txt", cell_x, cell_y, cell_size.first, cell_size.second);
}

void Cell::render()
{
	cell->render();
}