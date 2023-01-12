#include <iostream>
#include "Player.h"
#include "Grid2D.h"
#include <windows.h>
#include <time.h>

using namespace std;


// 화면 클리어용
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

	// 게임오브젝트 멤버 생성 후 추가한 부분
	//NewMap = new GameObject * [SizeX]; // 이거 쓰려다가 복잡해서 바꿈

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

	//Map[PtrPlayer->GetX()][PtrPlayer->GetY()] = PtrPlayer->GetId()[0]; // Id는 string인데 char배열처럼 해놨네? 한 글자만 나오게 한거구나 // GameObject때문에 필요없어짐

	// 현재 있는 몬스터 수만큼 렌더링
	for (int i = 0; i < CurrentGameObject; i++)
	{
		Map[NewMap[i]->GetX()][NewMap[i]->GetY()] = NewMap[i]->GetId()[0];
	}
}

// 맵 렌더링
void Grid2D::Draw()
{
	//system("cls"); // 멀티쓰레드? 방식이라 화면 지우는거랑 출력이랑 시간차가 생겨 깜박이는 것처럼 보이게 된다
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
//	//PtrPlayer->SetGrid(this); // 자기 자신을 넘기는게 this
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
			return NewMap[i]; // 이게 PtrEnemy + i 랑 같은거지?? 배열은 볼 때마다 헷갈리네
		}
	}

	return nullptr;
}

void Grid2D::AddGameObject(GameObject* InputObject)
{
	//PtrEnemy[CurrentEnemy++] = InputEnemy;
	NewMap[CurrentGameObject] = InputObject;
	NewMap[CurrentGameObject++]->SetGrid(this); // 자기 자신을 넘기는게 this. SetPlayer가 의미가 없어져서 여기로 왔다
}

void Grid2D::RemoveGameObject(string Id)
{
	bool bCheck = false; // 입력받은 친구가 친구리스트에 존재하는지 확인 후 저장하려는 변수

	// 친구가 0명이면 remove할 필요가 없다
	if (CurrentGameObject > 0)
	{
		int temp = -1; // 삭제할 친구 인덱스 저장용
		for (int i = 0; i < CurrentGameObject; i++)
		{
			if (NewMap[i]->GetId() == Id) // 이름이 겹치지 않는다고 가정(ID처럼)
			{
				temp = i;

				// 친구 리스트에 입력한 친구가 있으면 true로
				bCheck = true;

				break;
			}
		}

		// for문 다 돌았으니까 다 체크한거고, 친구 리스트에 친구가 존재하지 않으면 return
		if (bCheck != true)
		{
			cout << "Monster가 리스트에 존재하지 않습니다." << endl;
			return;
		}

		// 제가한 인덱스부터 뒤에 친구 앞으로 1칸씩 당기기
		for (int i = temp; i < CurrentGameObject - 1; i++)
		{
			NewMap[i] = NewMap[i + 1];
		}

		// FCount 1 줄이기
		--CurrentGameObject;
	}
	else
	{
		cout << "Monster가 없습니다." << endl;
	}
}

void Grid2D::CreateGameObject()
{
	// 몬스터 랜덤좌표에서 생성
	srand(time(NULL));
	NewMap[CurrentGameObject] = new GameObject("Monster", rand() % (SizeX - 2) + 1, rand() % (SizeY - 2) + 1);
	AddGameObject(NewMap[CurrentGameObject++]);
}

int Grid2D::GetCurrentGameObject()
{
	return CurrentGameObject;
}
