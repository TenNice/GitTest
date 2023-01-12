#pragma once
#include <iostream>

using namespace std;

class Stack
{
private:


public:

};


// 성능 안 좋은 구버전
class QueueOld
{
private:
	int Size;
	int* Array;
	int Front;
	int Rear;

public:
	QueueOld()
	{
		Size = 100;
		Array = new int[Size];
		Front = 0;
		Rear = 0;
	}
	QueueOld(int InputSize)
	{
		Size = InputSize;
		Array = new int[Size];
		Front = 0;
		Rear = 0;
	}
	~QueueOld()
	{
		delete[] Array;
	}

	void Enqueue(int InputNum)
	{
		if (Front >= Size)
		{
			cout << "사이즈 초과! 입력 불가!" << endl;
			return;
		}
		Array[Front++] = InputNum;
	}
	void Dequeue()
	{
		if (Front <= 0)
		{
			cout << "큐에 저장된 데이터가 없습니다." << endl;
			return;
		}

		cout << Array[0] << "이(가) 제거되었습니다.\n" << endl;

		for (int i = 0; i < Front - 1; i++)
		{
			Array[i] = Array[i + 1];
		}
		Front--;
	}

	void ShowArray(int Num)
	{
		if (Num < 0)
		{
			cout << "0이상의 숫자가 들어가야합니다." << endl;
			return;
		}
		cout << Array[Num] << endl;
	}

	int GetFront()
	{
		return Front;
	}
	int GetRear()
	{
		return Rear;
	}
};

class Queue
{
private:
	int Size;
	int* Array;
	int Front;
	int Rear;

public:
	Queue()
	{
		Size = 100;
		Array = new int[Size];
		Front = 0;
		Rear = 0;
	}
	Queue(int InputSize)
	{
		Size = InputSize;
		Array = new int[Size];
		Front = 0;
		Rear = 0;
	}
	~Queue()
	{
		delete[] Array;
	}

	void Enqueue(int InputNum)
	{
		// 큐가 꽉 찬 상태인지부터 확인
		if (Rear + 1 == Front || ((Rear == Size - 1) && (Front == 0)))
		{
			cout << "큐가 꽉 찼습니다." << endl;
			return;
		}

		// Rear가 Size - 1에 있으면 맨 앞으로 보내야한다.
		if (Rear >= Size - 1)
		{
			if (Front > 0)
			{
				Rear = -1;
			}
		}

		// 큐가 비어있으면 데이터만 넣고 Rear증가 X
		Rear == Front ? Array[Rear] = InputNum : Array[++Rear] = InputNum;
	}

	void Dequeue()
	{
		// 큐가 비어있는지부터 확인
		if (Front == Rear)
		{
			if (Array[Front] == NULL)
			{
				cout << "큐가 비어있습니다." << endl;
				return;
			}
			else // Front == Rear인데 데이터가 하나만 있는 경우
			{
				cout << Array[Front] << "이(가) 제거되었습니다." << endl;
				Array[Front] = NULL;
				return;
			}
		}

		cout << Array[Front] << "이(가) 제거되었습니다." << endl;
		Array[Front++] = NULL;

		// Front가 Size - 1에 있으면 맨 앞으로 보내야한다.
		if (Front > Size - 1)
		{
			if (Rear > 0)
			{
				Front = 0;
			}
		}
	}

	// 지금 스택에 저장되어 있는거 뒤에서부터 다 보여주기
	void ShowArray()
	{
		if (Rear >= Front)
		{
			for (int i = 0; i < Rear - Front + 1; i++)
			{
				cout << Array[i] << endl;
			}
		}
		else
		{
			for (int i = 0; i < Size - (Front - Rear - 1); i++)
			{
				cout << Array[i] << endl;
			}
		}
	}

	int GetFront()
	{
		return Front;
	}
	int GetRear()
	{
		return Rear;
	}
};