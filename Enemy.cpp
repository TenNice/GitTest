#include "Enemy.h"

/*
void Enemy::ProcessCollision() // 충돌처리하는 함수를 따로 만드는게 좋겠네!
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
// 4가지 방향 다 처리하거나, 좌우 상하로 나누거나
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

void Enemy::SetBound(int SizeX, int SizeY) // 미리 사이즈 받기
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
	cout << "\n" << Id << "이(가) 죽었습니다." << endl;
}
*/