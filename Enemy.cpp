#include "Enemy.h"

/*
void Enemy::ProcessCollision() // �浹ó���ϴ� �Լ��� ���� ����°� ���ڳ�!
{
	if (EnemyX <= 0)
	{
		EnemyX++;
	}
	else if (EnemyX >= MapSizeX - 1)
	{
		EnemyX = MapSizeX - 2;
	}
	if (EnemyY <= 0)
	{
		EnemyY++;
	}
	else if (EnemyY >= MapSizeY - 1)
	{
		EnemyY = MapSizeY - 2;
	}
}
*/

Enemy::Enemy()
{

}
Enemy::Enemy(string InputId, int X, int Y) : GameObject(InputId, X, Y)
{

}
Enemy::~Enemy()
{

}

/*
// 4���� ���� �� ó���ϰų�, �¿� ���Ϸ� �����ų�
void Enemy::Move(Direction InputDirection)
{
	//cout << "Move" << endl;

	switch (InputDirection)
	{
	case Direction::Up:
		EnemyY++;
		ProcessCollision();
		break;
	case Direction::Down:
		EnemyY--;
		ProcessCollision();
		break;
	case Direction::Right:
		EnemyX++;
		ProcessCollision();
		break;
	case Direction::Left:
		EnemyX--;
		ProcessCollision();
		break;

	default:
		break;
	}
}

string Enemy::GetId()
{
	return Id;
}

int Enemy::GetX()
{
	return EnemyX;
}
int Enemy::GetY()
{
	return EnemyY;
}

void Enemy::SetBound(int SizeX, int SizeY) // �̸� ������ �ޱ�
{
	MapSizeX = SizeX;
	MapSizeY = SizeY;
}

void Enemy::TakeDamage(float Damage)
{
	Health -= Damage;

	if (Health <= 0)
	{
		Dead();
	}
}

void Enemy::Dead()
{
	cout << "\n" << Id << "��(��) �׾����ϴ�." << endl;
}
*/