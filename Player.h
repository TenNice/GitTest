#pragma once // �갡 �ߺ� include �����ش�

// ����� �Լ� ����. ������ cpp���Ͽ���

#include <iostream>
#include "GameObject.h"

//class Grid2D;
using namespace std;

// enum�� 0���� ��Ī
//enum class Direction
//{
//	None,
//	Up,
//	Down,
//	Right,
//	Left,
//};


class Player : public GameObject
{
//private:
//	string Id;
//	int PlayerX, PlayerY;
//	float Damage;
//	
//
//	Grid2D* Grid;
//	//int MapSizeX, MapSizeY;
//
//	void ProcessCollision(); // �浹ó���ϴ� �Լ��� ���� ����°� ���ڳ�!
//
public:
	Player();
	Player(string InputId, int X, int Y);
	~Player();
//
//	// 4���� ���� �� ó���ϰų�, �¿� ���Ϸ� �����ų�
//	void Move(Direction InputDirection);
//	string GetId();
//	int GetX();
//	int GetY();
//	// void SetBound(int SizeX, int SizeY); // �̸� ������ �ޱ�. Grid��ü �޾ƿ��� �Լ� �����ϸ鼭 �ʿ������
//	void Attack();
//	void SetGrid(Grid2D* Grid);
};