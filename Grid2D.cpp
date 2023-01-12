#include <iostream>
#include "Player.h"
#include "Grid2D.h"
#include <windows.h>
#include <time.h>

using namespace std;


// ȭ�� Ŭ�����
void ClearLastPosition()
{
	_COORD Last;
	Last.X = 0;
	Last.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Last);
}



Grid2D::Grid2D()
{
	Map = new char* [SizeX];
	for (int i = 0; i < SizeX; i++)
	{
		Map[i] = new char[SizeY];
	}

	// ���ӿ�����Ʈ ��� ���� �� �߰��� �κ�
	//NewMap = new GameObject * [SizeX]; // �̰� �����ٰ� �����ؼ� �ٲ�

	CurrentGameObject = 0;
	//PtrEnemy = new Enemy * [MaxGameObject];
	NewMap = new GameObject * [MaxGameObject];
}
Grid2D::Grid2D(int X, int Y)
{
	SizeX = X, SizeY = Y;
	Map = new char* [SizeX];
	for (int i = 0; i < SizeX; i++)
	{
		Map[i] = new char[SizeY];
	}

	CurrentGameObject = 0;
	//PtrEnemy = new Enemy * [MaxGameObject];
	NewMap = new GameObject * [MaxGameObject];
}
Grid2D::~Grid2D()
{
	for (int i = 0; i < SizeX; i++)
	{
		delete[] Map[i];
	}
	delete[] Map;

	//delete[] PtrEnemy;
	delete[] NewMap;
}

void Grid2D::Update()
{
	// �ʱ�ȭ
	for (int i = 0; i < SizeX; i++)
	{
		for (int j = 0; j < SizeY; j++)
		{
			// �׵θ� �κ�. x�� 0or9�� ���� y�� 0or9�� ��
			if (i == 0 || i == SizeX - 1 || j == 0 || j == SizeY - 1) // �̰� ���� �� �ߴ�. ���� ���ĵ� �ǳ�
			{
				Map[i][j] = '#';
			}
			// �Ϲ����� ���
			else
			{
				Map[i][j] = ' ';
			}
		}
	}

	//Map[PtrPlayer->GetX()][PtrPlayer->GetY()] = PtrPlayer->GetId()[0]; // Id�� string�ε� char�迭ó�� �س���? �� ���ڸ� ������ �Ѱű��� // GameObject������ �ʿ������

	// ���� �ִ� ���� ����ŭ ������
	for (int i = 0; i < CurrentGameObject; i++)
	{
		Map[NewMap[i]->GetX()][NewMap[i]->GetY()] = NewMap[i]->GetId()[0];
	}
}

// �� ������
void Grid2D::Draw()
{
	//system("cls"); // ��Ƽ������? ����̶� ȭ�� ����°Ŷ� ����̶� �ð����� ���� �����̴� ��ó�� ���̰� �ȴ�
	ClearLastPosition();

	for (int i = 0; i < SizeY; i++)
	{
		for (int j = 0; j < SizeX; j++)
		{
			cout << Map[j][SizeY - i - 1] << " ";
		}
		cout << endl;
	}
}

//void Grid2D::SetPlayer(Player* InputPlayer)
//{
//	PtrPlayer = InputPlayer;
//	//PtrPlayer->SetGrid(this); // �ڱ� �ڽ��� �ѱ�°� this
//}

int Grid2D::GetSizeX()
{
	return SizeX;
}
int Grid2D::GetSizeY()
{
	return SizeY;
}

GameObject* Grid2D::GetGameObject(int X, int Y)
{
	for (int i = 0; i < CurrentGameObject; i++)
	{
		if (NewMap[i]->GetX() == X && NewMap[i]->GetY() == Y)
		{
			return NewMap[i]; // �̰� PtrEnemy + i �� ��������?? �迭�� �� ������ �򰥸���
		}
	}

	return nullptr;
}

void Grid2D::AddGameObject(GameObject* InputObject)
{
	//PtrEnemy[CurrentEnemy++] = InputEnemy;
	NewMap[CurrentGameObject] = InputObject;
	NewMap[CurrentGameObject++]->SetGrid(this); // �ڱ� �ڽ��� �ѱ�°� this. SetPlayer�� �ǹ̰� �������� ����� �Դ�
}

void Grid2D::RemoveGameObject(string Id)
{
	bool bCheck = false; // �Է¹��� ģ���� ģ������Ʈ�� �����ϴ��� Ȯ�� �� �����Ϸ��� ����

	// ģ���� 0���̸� remove�� �ʿ䰡 ����
	if (CurrentGameObject > 0)
	{
		int temp = -1; // ������ ģ�� �ε��� �����
		for (int i = 0; i < CurrentGameObject; i++)
		{
			if (NewMap[i]->GetId() == Id) // �̸��� ��ġ�� �ʴ´ٰ� ����(IDó��)
			{
				temp = i;

				// ģ�� ����Ʈ�� �Է��� ģ���� ������ true��
				bCheck = true;

				break;
			}
		}

		// for�� �� �������ϱ� �� üũ�ѰŰ�, ģ�� ����Ʈ�� ģ���� �������� ������ return
		if (bCheck != true)
		{
			cout << "Monster�� ����Ʈ�� �������� �ʽ��ϴ�." << endl;
			return;
		}

		// ������ �ε������� �ڿ� ģ�� ������ 1ĭ�� ����
		for (int i = temp; i < CurrentGameObject - 1; i++)
		{
			NewMap[i] = NewMap[i + 1];
		}

		// FCount 1 ���̱�
		--CurrentGameObject;
	}
	else
	{
		cout << "Monster�� �����ϴ�." << endl;
	}
}

void Grid2D::CreateGameObject()
{
	// ���� ������ǥ���� ����
	srand(time(NULL));
	NewMap[CurrentGameObject] = new GameObject("Monster", rand() % (SizeX - 2) + 1, rand() % (SizeY - 2) + 1);
	AddGameObject(NewMap[CurrentGameObject++]);
}

int Grid2D::GetCurrentGameObject()
{
	return CurrentGameObject;
}
