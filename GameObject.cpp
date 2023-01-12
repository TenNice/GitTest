// cpp������ Ŭ������ ����� �Լ��� �����Ѵ�.

#include "Grid2D.h"
#include "GameObject.h"

void GameObject::ProcessCollision() // �浹ó���ϴ� �Լ��� ���� ����°� ���ڳ�!
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

// 4���� ���� �� ó���ϰų�, �¿� ���Ϸ� �����ų�
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
void Player::SetBound(int SizeX, int SizeY) // �̸� ������ �ޱ�
{
	MapSizeX = SizeX;
	MapSizeY = SizeY;
}
*/

void GameObject::Attack()
{
	GameObject* GameObject = Grid->GetGameObject(GameObjectX + 1, GameObjectY); // X, Y�� �ִ� �� ���� ��ȯ. Grid2D�� Enemy���� ������ ������ Player�� Enemy�����ͺ����� ����� ������ ���� �ʿ䰡 ������
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


	GameObject = Grid->GetGameObject(GameObjectX + 1, GameObjectY + 1); // X, Y�� �ִ� �� ���� ��ȯ. Grid2D�� Enemy���� ������ ������ Player�� Enemy�����ͺ����� ����� ������ ���� �ʿ䰡 ������
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
	cout << "\n" << Id << "��(��) �׾����ϴ�." << endl;
	Grid->RemoveGameObject(Id);
}