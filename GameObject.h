#pragma once

#include <iostream>

class Grid2D;
using namespace std;

// enum�� 0���� ��Ī
enum class Direction
{
	None,
	Up,
	Down,
	Right,
	Left,
};

class GameObject
{
private:
	string Id;
	int GameObjectX, GameObjectY;
	float Damage;
	float Health;


	Grid2D* Grid;
	//int MapSizeX, MapSizeY;

	void ProcessCollision(); // �浹ó���ϴ� �Լ��� ���� ����°� ���ڳ�!

public:
	GameObject();
	GameObject(string InputId, int X, int Y);
	~GameObject();

	// 4���� ���� �� ó���ϰų�, �¿� ���Ϸ� �����ų�
	void Move(Direction InputDirection);
	string GetId();
	int GetX();
	int GetY();
	//void SetBound(int SizeX, int SizeY); // �̸� ������ �ޱ�. Grid��ü �޾ƿ��� �Լ� �����ϸ鼭 �ʿ������
	void Attack();
	void SetGrid(Grid2D* Grid);
	void TakeDamage(float Damage);
	void Dead();
};