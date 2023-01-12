// cpp파일은 클래스의 선언된 함수를 구현한다.

#include "Grid2D.h"
#include "GameObject.h"

void GameObject::ProcessCollision() // 충돌처리하는 함수를 따로 만드는게 좋겠네!
{
	if (GameObjectX <= 0)
	{
		GameObjectX++;
	}
	else if (GameObjectX >= Grid->GetSizeX() - 1)
	{
		GameObjectX = Grid->GetSizeX() - 2;
	}
	if (GameObjectY <= 0)
	{
		GameObjectY++;
	}
	else if (GameObjectY >= Grid->GetSizeY() - 1)
	{
		GameObjectY = Grid->GetSizeY() - 2;
	}
}

GameObject::GameObject()
{
	Id = "Default";
	GameObjectX = 2;
	GameObjectY = 2;
	Damage = 100;
	Health = 100;
}
GameObject::GameObject(string InputId, int X, int Y)
{
	Id = InputId;
	GameObjectX = X;
	GameObjectY = Y;
	Damage = 100;
	Health = 100;
}
GameObject::~GameObject()
{

}

// 4가지 방향 다 처리하거나, 좌우 상하로 나누거나
void GameObject::Move(Direction InputDirection)
{
	//cout << "Move" << endl;

	switch (InputDirection)
	{
	case Direction::Up:
		GameObjectY++;
		ProcessCollision();
		break;
	case Direction::Down:
		GameObjectY--;
		ProcessCollision();
		break;
	case Direction::Right:
		GameObjectX++;
		ProcessCollision();
		break;
	case Direction::Left:
		GameObjectX--;
		ProcessCollision();
		break;

	default:
		break;
	}
}

string GameObject::GetId()
{
	return Id;
}

int GameObject::GetX()
{
	return GameObjectX;
}
int GameObject::GetY()
{
	return GameObjectY;
}

/*
void Player::SetBound(int SizeX, int SizeY) // 미리 사이즈 받기
{
	MapSizeX = SizeX;
	MapSizeY = SizeY;
}
*/

void GameObject::Attack()
{
	GameObject* GameObject = Grid->GetGameObject(GameObjectX + 1, GameObjectY); // X, Y에 있는 적 정보 반환. Grid2D가 Enemy정보 가지고 있으니 Player가 Enemy포인터변수를 멤버로 가지고 있을 필요가 없구나
	if (GameObject != nullptr)
	{
		GameObject->TakeDamage(Damage);
	}

	GameObject = Grid->GetGameObject(GameObjectX, GameObjectY + 1);
	if (GameObject != nullptr)
	{
		GameObject->TakeDamage(Damage);
	}

	GameObject = Grid->GetGameObject(GameObjectX - 1, GameObjectY);
	if (GameObject != nullptr)
	{
		GameObject->TakeDamage(Damage);
	}

	GameObject = Grid->GetGameObject(GameObjectX, GameObjectY - 1);
	if (GameObject != nullptr)
	{
		GameObject->TakeDamage(Damage);
	}


	GameObject = Grid->GetGameObject(GameObjectX + 1, GameObjectY + 1); // X, Y에 있는 적 정보 반환. Grid2D가 Enemy정보 가지고 있으니 Player가 Enemy포인터변수를 멤버로 가지고 있을 필요가 없구나
	if (GameObject != nullptr)
	{
		GameObject->TakeDamage(Damage);
	}

	GameObject = Grid->GetGameObject(GameObjectX - 1, GameObjectY + 1);
	if (GameObject != nullptr)
	{
		GameObject->TakeDamage(Damage);
	}

	GameObject = Grid->GetGameObject(GameObjectX - 1, GameObjectY - 1);
	if (GameObject != nullptr)
	{
		GameObject->TakeDamage(Damage);
	}

	GameObject = Grid->GetGameObject(GameObjectX + 1, GameObjectY - 1);
	if (GameObject != nullptr)
	{
		GameObject->TakeDamage(Damage);
	}
}

void GameObject::SetGrid(Grid2D* Grid)
{
	this->Grid = Grid;
}

void GameObject::TakeDamage(float Damage)
{
	Health -= Damage;

	if (Health <= 0)
	{
		Dead();
	}
}

void GameObject::Dead()
{
	cout << "\n" << Id << "이(가) 죽었습니다." << endl;
	Grid->RemoveGameObject(Id);
}