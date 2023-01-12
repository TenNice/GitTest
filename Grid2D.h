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
	//Enemy** PtrEnemy = nullptr; // Enemy ���� �����״� �迭�� �Ϸ���
	int CurrentGameObject; // ����
	int MaxGameObject = 100; // �� �ִ� ��

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
	
	GameObject** NewMap; // ��� �� 2��¥����
	void CreateGameObject();
	int GetCurrentGameObject();
};