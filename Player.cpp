// cpp������ Ŭ������ ����� �Լ��� �����Ѵ�.

#include "Player.h"
#include "Grid2D.h"
#include "Enemy.h"

/*
void Player::ProcessCollision() // �浹ó���ϴ� �Լ��� ���� ����°� ���ڳ�!
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
// 4���� ���� �� ó���ϰų�, �¿� ���Ϸ� �����ų�
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


//void Player::SetBound(int SizeX, int SizeY) // �̸� ������ �ޱ�
//{
//	MapSizeX = SizeX;
//	MapSizeY = SizeY;
//}


void Player::Attack()
{
	Enemy* Enemy = Grid->GetEnemy(PlayerX, PlayerY); // X, Y�� �ִ� �� ���� ��ȯ. Grid2D�� Enemy���� ������ ������ Player�� Enemy�����ͺ����� ����� ������ ���� �ʿ䰡 ������
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