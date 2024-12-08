#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include "Game.h"

Game::Game()
{
	P1Score = 0;
	P2Score = 0;
	GameOver = false;
}

int Game::GetP1Score() const
{
	return P1Score;
}

int Game::GetP2Score() const
{
	return P2Score;
}

bool Game::bGameOver() const
{
	return GameOver;
}

int Game::GetGameWinner() const
{
	return GameWinner;
}

void Game::InitGameField()
{
	for (int i = 0; i < FIELDSIZE_Y; i++)
	{
		for (int j = 0; j < FIELDSIZE_X; j++)
		{
			PlayingField[i][j] = ' ';
		}
	}
}

void Game::BeginPlay()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &info);

	Player1.SetPlayerNum(1);
	Player2.SetPlayerNum(2);
	InitGameField();
	Player1.BeginPlay();
	Player2.BeginPlay();
	GameBall.BeginPlay();
	Render();
}

void Game::Tick()
{
	if (GetKeyState(VK_ESCAPE) & 0x8000)
	{
		GameOver = true;
	}

	Player1.Tick();
	Player2.Tick();
	GameBall.Tick();

	//player1 ball control
	if (GameBall.GetPositionX() == (Player1.GetPositionX() + 1) && GameBall.GetRemainingDelay() ==0) //right in front
	{
		if (GameBall.GetPositionY() == (Player1.GetPositionY() + 1) || GameBall.GetPositionY() == (Player1.GetPositionY() - 1)) //1 below or above
		{
			GameBall.BounceY();
			GameBall.BounceX();
		}
		else if (GameBall.GetPositionY() == (Player1.GetPositionY()))
		{
			GameBall.BounceX();
		}
	}

	//player2 ball control
	if (GameBall.GetPositionX() == (Player2.GetPositionX() - 1) && GameBall.GetRemainingDelay() == 0) //right in front
	{
		if (GameBall.GetPositionY() == (Player2.GetPositionY() + 1) || GameBall.GetPositionY() == (Player2.GetPositionY() - 1)) //1 below or above
		{
			GameBall.BounceY();
			GameBall.BounceX();
		}
		else if (GameBall.GetPositionY() == (Player2.GetPositionY()))
		{
			GameBall.BounceX();
		}
	}

	//Player Scoring
	if (GameBall.GetPositionX() < Player1.GetPositionX() && GameBall.GetRemainingDelay() == 0)
	{
		P2Score++;
		GameBall.ResetBall();
		if (P2Score > 10)
		{
			GameWinner = 2;
			GameOver = true;
		}
	}
	
	if (GameBall.GetPositionX() > Player2.GetPositionX() && GameBall.GetRemainingDelay() == 0)
	{
		P1Score++;
		GameBall.ResetBall();
		if (P1Score > 10)
		{
			GameWinner = 1;
			GameOver = true;
		}
	}

	UpdateField();
	Render();
	PrintScore();
}

void Game::UpdateField()
{
	InitGameField(); //Clears the field

	PlayingField[Player1.GetPositionY()][Player1.GetPositionX()] = Player1.Avatar;
	PlayingField[Player2.GetPositionY()][Player2.GetPositionX()] = Player2.Avatar;
	PlayingField[GameBall.GetPositionY()][GameBall.GetPositionX()] = GameBall.Avatar;
}

void Game::Render()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 0,0 };
	SetConsoleCursorPosition(hConsole, pos);
	

	for (int i = 0; i < FIELDSIZE_Y; i++)
	{
		for (int j = 0; j < FIELDSIZE_X; j++)
		{
			std::cout << PlayingField[i][j];
		}
		std::cout << std::endl;
	}
}

void Game::PrintScore()
{
	std::cout << "Player 1: " << P1Score << "                                                  Player 2: " << P2Score;

}