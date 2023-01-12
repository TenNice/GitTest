#pragma once

#include <iostream>
//#include "Player.h" // Direction 쓰려고
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
//	void ProcessCollision(); // 충돌처리하는 함수를 따로 만드는게 좋겠네!
//
public:
	Enemy();
	Enemy(string InputId, int X, int Y);
	~Enemy();
//
//	// 4가지 방향 다 처리하거나, 좌우 상하로 나누거나
//	void Move(Direction InputDirection);
//	string GetId();
//	int GetX();
//	int GetY();
//	void SetBound(int SizeX, int SizeY); // 미리 사이즈 받기
//	void TakeDamage(float Damage);
//	void Dead();
};