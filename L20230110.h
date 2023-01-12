#pragma once
#include <iostream>

using namespace std;

class Player
{
private:
	string Id;
	int PlayerX, PlayerY;

public:
	Player()
	{
		Id = "Default";
		PlayerX = 2;
		PlayerY = 2;
	}
	Player(string InputId, int X, int Y)
	{
		Id = InputId;
		PlayerX = X;
		PlayerY = Y;
	}
	~Player()
	{

	}

	string GetId()
	{
		return Id;
	}

	int GetX()
	{
		return PlayerX;
	}
	int GetY()
	{
		return PlayerY;
	}

};

class Grid2D
{
private:
	int SizeX = 20, SizeY = 20;
	char** Map;
	Player* PtrPlayer = nullptr;

public:
	Grid2D()
	{
		Map = new char* [SizeX];
		for (int i = 0; i < SizeX; i++)
		{
			Map[i] = new char[SizeY];
		}
	}
	Grid2D(int X, int Y)
	{
		SizeX = X, SizeY = Y;
		Map = new char* [SizeX];
		for (int i = 0; i < SizeX; i++)
		{
			Map[i] = new char[SizeY];
		}
	}
	~Grid2D()
	{
		for (int i = 0; i < SizeX; i++)
		{
			delete[] Map[i];
		}
		delete[] Map;
	}

	void Update()
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

		Map[PtrPlayer->GetX()][PtrPlayer->GetY()] = PtrPlayer->GetId()[0]; // Id�� string�ε� char�迭ó�� �س���? �� ���ڸ� ������ �Ѱű���
	}

	// �� ������
	void Draw()
	{
		for (int i = 0; i < SizeY; i++)
		{
			for (int j = 0; j < SizeX; j++)
			{
				cout << Map[j][SizeY - i - 1] << " ";
			}
			cout << endl;
		}
	}

	void SetPlayer(Player* InputPlayer)
	{
		PtrPlayer = InputPlayer;
	}

};