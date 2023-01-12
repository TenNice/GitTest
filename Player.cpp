// cpp파일은 클래스의 선언된 함수를 구현한다.

#include "Player.h"
#include "Grid2D.h"
#include "Enemy.h"

/*
void Player::ProcessCollision() // 충돌처리하는 함수를 따로 만드는게 좋겠네!
{
	if (PlayerX <= 0)
	{
		PlayerX++;
	}
	else if (PlayerX >= Grid->GetSizeX() - 1)
	{
		PlayerX = Grid->GetSizeX() - 2;
	}
	if (PlayerY <= 0)
	{
		PlayerY++;
	}
	else if (PlayerY >= Grid->GetSizeY() - 1)
	{
		PlayerY = Grid->GetSizeY() - 2;
	}
}
*/

Player::Player()
{

}
Player::Player(string InputId, int X, int Y) :GameObject(InputId, X, Y)
{

}
Player::~Player()
{

}

/*
// 4가지 방향 다 처리하거나, 좌우 상하로 나누거나
void Player::Move(Direction InputDirection)
{
	cout << "Move" << endl;

	switch (InputDirection)
	{
	case Direction::Up:
		PlayerY++;
		ProcessCollision();
		break;
	case Direction::Down:
		PlayerY--;
		ProcessCollision();
		break;
	case Direction::Right:
		PlayerX++;
		ProcessCollision();
		break;
	case Direction::Left:
		PlayerX--;
		ProcessCollision();
		break;

	default:
		break;
	}
}

string Player::GetId()
{
	return Id;
}

int Player::GetX()
{
	return PlayerX;
}
int Player::GetY()
{
	return PlayerY;
}


//void Player::SetBound(int SizeX, int SizeY) // 미리 사이즈 받기
//{
//	MapSizeX = SizeX;
//	MapSizeY = SizeY;
//}


void Player::Attack()
{
	Enemy* Enemy = Grid->GetEnemy(PlayerX, PlayerY); // X, Y에 있는 적 정보 반환. Grid2D가 Enemy정보 가지고 있으니 Player가 Enemy포인터변수를 멤버로 가지고 있을 필요가 없구나
	if (Enemy != nullptr)
	{
		Enemy->TakeDamage(Damage);
	}
}

void Player::SetGrid(Grid2D* Grid)
{
	this->Grid = Grid;
}
*/