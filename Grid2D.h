#pragma once

#include <iostream>
#include "Player.h"
#include "Enemy.h"

using namespace std;

class GameObject;


class Grid2D
{
private:
	int SizeX = 20, SizeY = 20;
	char** Map;
	//Player* PtrPlayer = nullptr;
	//Enemy** PtrEnemy = nullptr; // Enemy 여럿 있을테니 배열로 하려고
	int CurrentGameObject; // 현재
	int MaxGameObject = 100; // 적 최대 수

public:
	Grid2D();
	Grid2D(int X, int Y);
	~Grid2D();
	void Update();
	void Draw();
	//void SetPlayer(Player* InputPlayer);
	void AddGameObject(GameObject* InputObject);
	void RemoveGameObject(string Id);
	int GetSizeX();
	int GetSizeY();
	GameObject* GetGameObject(int X, int Y);
	
	GameObject** NewMap; // 얘는 왜 2개짜리야
	void CreateGameObject();
	int GetCurrentGameObject();
};