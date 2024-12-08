#pragma once
class Player
{
private:
	int PositionX=0;
	int PositionY=0;
	int PlayerNum=0;
public:
	Player();
	const char Avatar = '|';

	void MoveUp();
	void MoveDown();
	void BeginPlay();
	void Tick();

	int GetPositionX();
	int GetPositionY();

	void SetPlayerNum(int PNum);
};