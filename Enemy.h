#pragma once

#include <iostream>
//#include "Player.h" // Direction ������
#include "GameObject.h"

using namespace std;

//class Grid2D;

class Enemy : public GameObject
{
//private:
//	string Id;
//	int EnemyX, EnemyY;
//	int MapSizeX, MapSizeY;
//	float Health;
//	Grid2D Grid;
//
//	void ProcessCollision(); // �浹ó���ϴ� �Լ��� ���� ����°� ���ڳ�!
//
public:
	Enemy();
	Enemy(string InputId, int X, int Y);
	~Enemy();
//
//	// 4���� ���� �� ó���ϰų�, �¿� ���Ϸ� �����ų�
//	void Move(Direction InputDirection);
//	string GetId();
//	int GetX();
//	int GetY();
//	void SetBound(int SizeX, int SizeY); // �̸� ������ �ޱ�
//	void TakeDamage(float Damage);
//	void Dead();
};