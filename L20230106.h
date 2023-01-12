#pragma once
#include <iostream>

using namespace std;

class Stack
{
private:


public:

};


// ���� �� ���� ������
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
			cout << "������ �ʰ�! �Է� �Ұ�!" << endl;
			return;
		}
		Array[Front++] = InputNum;
	}
	void Dequeue()
	{
		if (Front <= 0)
		{
			cout << "ť�� ����� �����Ͱ� �����ϴ�." << endl;
			return;
		}

		cout << Array[0] << "��(��) ���ŵǾ����ϴ�.\n" << endl;

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
			cout << "0�̻��� ���ڰ� �����մϴ�." << endl;
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
		// ť�� �� �� ������������ Ȯ��
		if (Rear + 1 == Front || ((Rear == Size - 1) && (Front == 0)))
		{
			cout << "ť�� �� á���ϴ�." << endl;
			return;
		}

		// Rear�� Size - 1�� ������ �� ������ �������Ѵ�.
		if (Rear >= Size - 1)
		{
			if (Front > 0)
			{
				Rear = -1;
			}
		}

		// ť�� ��������� �����͸� �ְ� Rear���� X
		Rear == Front ? Array[Rear] = InputNum : Array[++Rear] = InputNum;
	}

	void Dequeue()
	{
		// ť�� ����ִ������� Ȯ��
		if (Front == Rear)
		{
			if (Array[Front] == NULL)
			{
				cout << "ť�� ����ֽ��ϴ�." << endl;
				return;
			}
			else // Front == Rear�ε� �����Ͱ� �ϳ��� �ִ� ���
			{
				cout << Array[Front] << "��(��) ���ŵǾ����ϴ�." << endl;
				Array[Front] = NULL;
				return;
			}
		}

		cout << Array[Front] << "��(��) ���ŵǾ����ϴ�." << endl;
		Array[Front++] = NULL;

		// Front�� Size - 1�� ������ �� ������ �������Ѵ�.
		if (Front > Size - 1)
		{
			if (Rear > 0)
			{
				Front = 0;
			}
		}
	}

	// ���� ���ÿ� ����Ǿ� �ִ°� �ڿ������� �� �����ֱ�
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