#include"Ball.h"

Ball::Ball()
{

}

void Ball::BeginPlay()
{
	ResetBall();
}

void Ball::Tick()
{
	if (BallDelay <= 0)
	{
		if (PosY <= 0 || PosY >=19)
		{
			BounceY();
		}

		if (PosX <= 0 || PosX >=79)
		{
			BounceX();
		}

		PosX += XDir;
		PosY += YDir;

		BallDelay = 10 - BallSpeed;
	}
	else
	{
		BallDelay--;
	}
}

void Ball::ResetBall()
{
	PosX = 40;
	PosY = 10;
}

void Ball::BounceX()
{
	XDir *= -1;
}

void Ball::BounceY()
{
	YDir *= -1;
}

int Ball::GetPositionX() const
{
	return PosX;
}

int Ball::GetPositionY() const
{
	return PosY;
}

int Ball::GetRemainingDelay() const
{
	return BallDelay;
}