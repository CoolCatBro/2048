#include "Game.hpp"

#include  <vector>

using std::vector;
using std::to_string;

Game::Game()
{
	srand(time(nullptr));

	max = 2;

	numgrid = new int*[grid_y];
	for (int i = 0; i < grid_y; i++)
	{
		numgrid[i] = new int[grid_x]();
	}
	_generateRandom();
	_generateRandom();
}

void Game::controls( char ch)
{
	if (ch == UP)
	{
		if (_checkUp())
		{
			_shiftUp();
			_generateRandom();
		}
    }
	if (ch == LEFT)
	{
		if (_checkLeft())
		{
			_shiftLeft();
			_generateRandom();
		}
	}
	if (ch == RIGHT)
	{
		if (_checkRight())
		{
			_shiftRight();
			_generateRandom();
		}
	}
	if (ch == DOWN)
	{
		if (_checkDown())
		{
			_shiftDown();
			_generateRandom();
		}
	}
}

bool Game :: victory()
{
	if (max == 2048)
		return true;
	else
		return false;
}

bool Game::lost()
{
	if (!_checkUp() && !_checkLeft() && !_checkRight() && !_checkDown())
		return true;
	else
		return false;
}

void Game::render()
{
	for (int i = 0; i < grid_y; i++)
	{
		for (int j = 0; j < grid_x; j++)
		{
			if (numgrid[i][j] != 0)
			{
				grid[i][j].writeCell("    ");
				grid[i][j].writeCell(to_string(numgrid[i][j]));
			}
			else
				grid[i][j].writeCell("    ");
		}
	}
	Level::render();

	if (victory())
	{
		GameEngine.moveXY(GameEngine.screen_width / 2, GameEngine.screen_height / 2);
		GameEngine.printW("You Won");
		return;
	}

	if (lost())
	{
		GameEngine.moveXY(GameEngine.screen_width / 2, GameEngine.screen_height / 2);
		GameEngine.printW("You Lost");
		return;
	}

}



void Game :: _shiftUp()
{
	for (int i = 0; i < grid_x; i++)
	{
		vector<int> temp(grid_y),res(grid_y);

		for (int j = 0, k = 0; j < grid_y; j++)
		{
			if (numgrid[j][i])
			{
				temp[k] = numgrid[j][i];
				k++;
			}
		}

		for (int j = 0; j < grid_y; j++)
		{
			if (j < grid_y - 1 && temp[j + 1] == temp[j])
			{
				temp[j] *= 2;

				if (temp[j] > max)
					max = temp[j];

				temp[j + 1] = 0;
			}
		}

		for (int j = 0, k = 0; j < grid_y; j++)
		{
			if (temp[j])
			{
				res[k] = temp[j];
				k++;
			}
		}

		for (int j = 0; j < grid_y; j++)
		{
			numgrid[j][i] = res[j];
		}
	}
}

void Game ::_shiftLeft()
{
	for (int i = 0; i < grid_y; i++)
	{
		vector<int> temp(grid_x), res(grid_x);

		for (int j = 0, k = 0; j < grid_x; j++)
		{
			if (numgrid[i][j])
			{
				temp[k] = numgrid[i][j];
				k++;
			}
		}

		for (int j = 0; j < grid_x; j++)
		{
			if (j < grid_x - 1 && temp[j + 1] == temp[j])
			{
				temp[j] *= 2;

				if (temp[j] > max)
					max = temp[j];

				temp[j + 1] = 0;
			}
		}

		for (int j = 0, k = 0; j < grid_x; j++)
		{
			if (temp[j])
			{
				res[k] = temp[j];
				k++;
			}
		}

		for (int j = 0; j < grid_x; j++)
		{
			numgrid[i][j] = res[j];
		}
	}
}

void Game ::_shiftRight()
{
	for (int i = 0; i < grid_y; i++)
	{
		vector<int> temp(grid_x), res(grid_x);

		for (int j = grid_x - 1, k = grid_x - 1 ; j >= 0; j--)
		{
			if (numgrid[i][j])
			{
				temp[k] = numgrid[i][j];
				k--;
			}
		}

		for (int j = grid_x - 1; j >= 0; j--)
		{
			if (j > 0 && temp[j - 1] == temp[j])
			{
				temp[j] *= 2;

				if (temp[j] > max)
					max = temp[j];

				temp[j - 1] = 0;
			}
		}

		for (int j = grid_x - 1, k = grid_x - 1; j >= 0; j--)
		{
			if (temp[j])
			{
				res[k] = temp[j];
				k--;
			}
		}

		for (int j = 0; j < grid_x; j++)
		{
			numgrid[i][j] = res[j];
		}
	}
}

void Game ::_shiftDown()
{
	for (int i = 0; i < grid_x; i++)
	{
		vector<int> temp(grid_y), res(grid_y);

		for (int j = grid_y -1, k = 0; j >= 0; j--)
		{
			if (numgrid[j][i])
			{
				temp[k] = numgrid[j][i];
				k++;
			}
		}

		for (int j = grid_y - 1 ; j >= 0; j--)
		{
			if (j > 0  &&  temp[j - 1] == temp[j])
			{
				temp[j] *= 2;

			    if (temp[j] > max)
					max = temp[j];

				temp[j - 1] = 0;
			}
		}

		for (int j = grid_y - 1, k = grid_y - 1; j >=0; j--)
		{
			if (temp[j])
			{
				res[k] = temp[j];
				k--;
			}
		}

		for (int j = 0; j < grid_y; j++)
		{
			numgrid[j][i] = res[j];
		}
	}
}

bool Game::_checkUp()
{
	for (int i = 0; i < grid_x; i++)
	{
		bool empty = false;
		int last = 0;

		for (int j = 0; j < grid_y; j++)
		{
			if (!numgrid[j][i]  && !empty)
			{
				empty = true;
				continue;
			}
			else if (numgrid[j][i])
			{
			   	if (last == numgrid[j][i])
					return true;
				else
					last = numgrid[j][i];
			}


			if (empty)
			{
				if (numgrid[j][i])
					return true;
			}
		}
	}
	return false;
}

bool Game::_checkLeft()
{
	for (int i = 0; i < grid_y; i++)
	{
		bool empty = false;
		int last = 0;

		for (int j = 0; j < grid_x; j++)
		{
			if (!numgrid[i][j]  && !empty)
			{
				empty = true;
				continue;
			}
			else if(numgrid[i][j])
			{
				if (last == numgrid[i][j])
					return true;
				else
					last = numgrid[i][j];
			}

			if (empty)
			{
				if (numgrid[i][j])
					return true;
			}
		}
	}
	return false;
}

bool Game::_checkRight()
{
	for (int i = 0; i < grid_y; i++)
	{
		bool empty = false;
		int last = 0;
		for (int j = grid_x-1; j >=0; j--)
		{
			if (!numgrid[i][j]  && !empty)
			{
				empty = true;
				continue;
			}
			else if(numgrid[i][j])
			{
				if (last == numgrid[i][j])
					return true;
				else
					last = numgrid[i][j];
			}

			if (empty)
			{
				if (numgrid[i][j])
					return true;
			}
		}
	}
	return false;
}

bool Game::_checkDown()
{
	for (int i = 0; i < grid_x; i++)
	{
		bool empty = false;
		int last = 0;
		for (int j = grid_y-1; j >=0; j--)
		{
			if (!numgrid[j][i] && !empty)
			{
				empty = true;
				continue;
			}
			else if(numgrid[j][i])
			{
				if (last == numgrid[j][i])
					return true;
				else
					last = numgrid[j][i];
			}

			if (empty)
			{
				if (numgrid[j][i])
					return true;
			}
		}
	}
	return false;
}

void Game::_generateRandom()
{
		int x = rand() % grid_x;
		int y = rand() % grid_y;

		while (numgrid[x][y] != 0)
		{
			x = rand() % grid_x;
			y = rand() % grid_y;
		}

		int prob = rand() % 100 + 1;
		if (prob > 10 || max < 8)
			numgrid[x][y] = 2;
		else
			numgrid[x][y] = 4;
}