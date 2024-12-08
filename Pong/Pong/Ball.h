#pragma once
class Ball
{
private:
	int PosX = 40;
	int PosY = 10;
	int XDir = 1;
	int YDir = 1;
	int BallDelay = 0;
	int BallSpeed = 5;
public:
	const char Avatar = 'o';

	Ball();

	void BeginPlay();
	void Tick();

	void BounceX();
	void BounceY();
	void ResetBall();

	int GetPositionX() const;
	int GetPositionY() const;
	int GetRemainingDelay() const;
};