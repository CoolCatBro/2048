#include "Player.hpp"
#include <iostream>

using std::cout;
using std::cin;

int main()
{
	cout << "< Just a short warning : It is still in testing phase so it may give error if grid is out of bounds of your screen.\n try increasing your screen resolution if it happen> : )\n\n";
	cout << "Enter the size of board:";
	cin >> grid_x >> grid_y;
	Player yourbro;
	yourbro.play();
	return 0;
}