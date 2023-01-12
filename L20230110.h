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
		// 초기화
		for (int i = 0; i < SizeX; i++)
		{
			for (int j = 0; j < SizeY; j++)
			{
				// 테두리 부분. x가 0or9일 때랑 y가 0or9일 때
				if (i == 0 || i == SizeX - 1 || j == 0 || j == SizeY - 1) // 이건 생각 못 했다. 조건 합쳐도 되네
				{
					Map[i][j] = '#';
				}
				// 일반적인 경우
				else
				{
					Map[i][j] = ' ';
				}
			}
		}

		Map[PtrPlayer->GetX()][PtrPlayer->GetY()] = PtrPlayer->GetId()[0]; // Id는 string인데 char배열처럼 해놨네? 한 글자만 나오게 한거구나
	}

	// 맵 렌더링
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