#include "Player.h"
#include <Windows.h>

Player::Player()
{
	PositionX=0;
	PositionY=0;
	PlayerNum=0;
}

void Player::MoveDown()
{
	if (PositionY < 19)
	{
		PositionY++;
	}
}

void Player::MoveUp()
{
	if (PositionY > 0)
	{
		PositionY--;
	}
}

void Player::BeginPlay()
{
	PositionX = (PlayerNum == 1) ? 5 : 74;
	PositionY = 10;
}

void Player::Tick()
{
	if (PlayerNum == 1)
	{
		if (GetKeyState('W') & 0x8000)
		{
			MoveUp();
		}

		if (GetKeyState('S') & 0x8000)
		{
			MoveDown();
		}
	}
	else
	{
		if (GetKeyState(VK_UP) & 0x8000)
		{
			MoveUp();
		}
		
		if (GetKeyState(VK_DOWN) & 0x8000)
		{
			MoveDown();
		}
	}
}

int Player::GetPositionX()
{
	return PositionX;
}
int Player::GetPositionY()
{
	return PositionY;
}

void Player::SetPlayerNum(int PNum)
{
	PlayerNum = PNum;
}