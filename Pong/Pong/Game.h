#pragma once
#include "Player.h"
#include "Ball.h"

#define FIELDSIZE_X 80
#define FIELDSIZE_Y 20

class Game 
{
private:
	int P1Score;
	int P2Score;
	bool GameOver;
	int GameWinner = -1;

	void InitGameField();
	void UpdateField();
	void Render(); //Renders the field

	Player Player1;
	Player Player2;

	Ball GameBall;

public:
	char PlayingField[FIELDSIZE_Y][FIELDSIZE_X];

	Game();
	int GetP1Score() const;
	int GetP2Score() const;
	bool bGameOver() const;
	int GetGameWinner() const;

	void BeginPlay(); //Game setup
	void Tick(); //Runs every frame

	void PrintScore();

};