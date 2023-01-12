#pragma once

#include <iostream>

class Grid2D;
using namespace std;

// enum은 0부터 매칭
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

	void ProcessCollision(); // 충돌처리하는 함수를 따로 만드는게 좋겠네!

public:
	GameObject();
	GameObject(string InputId, int X, int Y);
	~GameObject();

	// 4가지 방향 다 처리하거나, 좌우 상하로 나누거나
	void Move(Direction InputDirection);
	string GetId();
	int GetX();
	int GetY();
	//void SetBound(int SizeX, int SizeY); // 미리 사이즈 받기. Grid객체 받아오는 함수 구현하면서 필요없어짐
	void Attack();
	void SetGrid(Grid2D* Grid);
	void TakeDamage(float Damage);
	void Dead();
};