#include <iostream>
#include "Game.h"

int main(void)
{
	int PlayerChoice = -1;
	Game Pong;
	
	std::cout << "Welcome to PONG!!!" << std::endl;
	std::cout << "1: Start Game\n2: Quit" << std::endl;
	std::cin >> PlayerChoice;

	if (PlayerChoice != 1)
	{
		return 0;
	}

	Pong.BeginPlay();
	while (!Pong.bGameOver())
	{
		Pong.Tick();
	}

	if (Pong.GetGameWinner() > 0)
	{
		if (Pong.GetGameWinner() == 1)
		{
			std::cout << "\nPlayer 1 Won!" << std::endl;
		}
		else
		{
			std::cout << "\nPlayer 2 Won!" << std::endl;
		}
		std::getchar();
	}
	return 0;
}
