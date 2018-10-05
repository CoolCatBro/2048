#include "Player.hpp"
#include <conio.h>

void Player::play()
{
  char key='\0';

  Level::render();
  GameEngine.refresh();

  while(1)
  {
	  Sleep(timeout);
	  if (_kbhit())
	  {
		  key = _getch();
	  }
	  if(key =='q')
		  break;
	  Game::controls(key);
      GameEngine.clear();
      Game::render();
      GameEngine.refresh();
  }
  system("pause");
}