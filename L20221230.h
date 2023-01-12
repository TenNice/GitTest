#pragma once

#include <conio.h> // _getch() ������

int FactorialLimited(int N)
{
	static int Cnt = 0; // ����ƽ ������ ����� ���� ������ ������ �� �Լ� �������� ����. ����Ȱ� ����ƽ �����ΰ�
	bool bFirstCall = ++Cnt == 1; // ++Cnt == 1 �̸� true�� ���� �ƴϸ� false�� ����

	// Cnt�� 10�̻����� üũ
	if (Cnt >= 10)
	{
		cout << "10�� �̻� ȣ��Ǿ� �ߴ��մϴ�. ����ε� ������� ������ �ʾҽ��ϴ�." << endl;
		//cout << "Cnt : " << Cnt << endl;
		//Cnt = 0;
		return 1;
	}

	// ����Լ� ���� ����
	else if (N <= 1)
	{
		//cout << "Cnt : " << Cnt << endl;
		//Cnt = 0;
		return 1;
	}
	
	// FirstCall���� Ȯ���Ϸ��� �ٷ� �����ϸ� �� �Ǿ Result�� ����� ��Ҵ�.
	int Result = N * FactorialLimited(N - 1);
	
	if (bFirstCall)
	{
		cout << "Cnt : " << Cnt << endl;
		Cnt = 0;
	}

	return Result;
}

struct Coordinate
{
	int X;
	int Y;

	Coordinate()
	{

	}

	Coordinate(int num1, int num2)
	{
		X = num1;
		Y = num2;
	}
};

struct Rect
{
	float Width;
	float Height;
	float Area;
	float Circumference;
};

void CalRect(Rect &Rect)
{
	Rect.Area = Rect.Height * Rect.Width;
	Rect.Circumference = 2 * (Rect.Height + Rect.Width);
}

void PlusOne(Rect* Rect)
{
	(*Rect).Height++; // Rect->Height++
	(*Rect).Width++; // Rect->Width++
}

enum Day
{
	Mon,
	Tue,
	Wed,
	Thu,
	Fri,
	Sat,
	Sun,
	Not
};

struct Student
{
	string Name;
	int Age;
	int MathScore;
	int EngScore;
	Day Day;
	Coordinate Coordinate;
	Student* Parents;

	Student()
	{

	}

	Student(string name, int age, int mScore, int eScore) // Day day, Coordinate coordinate�� �����ڿ��� �̸� �� �޳�??
	{
		Name = name;
		Age = age;
		MathScore = mScore;
		EngScore = eScore;
	}
};

// Student ����ü Ÿ���� �迭�� ������ �ִ� ����ü
struct Club
{
	string Name;
	int StudentNumber = 10;
	Student Students[10];

	Club()
	{

	}

	Club(Student InputStudents[])
	{
		for (int i = 0; i < StudentNumber; i++)
		{
			Students[i] = InputStudents[i];
		}
	}

};


void PrintLocation(Student Student)
{
	if (Student.Coordinate.X == 10 && Student.Coordinate.Y == 10)
	{
		cout << "(10,10)�� �ִ� �л��� : " << Student.Name << endl;
	}
}

void PrintLocation1(Student Student[], int StudentNum)
{
	for (int i = 0; i < StudentNum; i++)
	{
		if ((Student + i)->Coordinate.X == 10 && (Student + i)->Coordinate.Y == 10)
		{
			cout << "(10,10)�� �ִ� �л��� : " << (Student + i)->Name << endl;
		}
	//	if (Student[i].Coordinate.X == 10 && Student[i].Coordinate.Y == 10)
	//	{
	//		cout << "(10,10)�� �ִ� �л��� : " << Student[i].Name << endl;
	//	}
	}
}

void PrintLocation2(Club ManyStudents, int StudentNum)
{
	for (int i = 0; i < StudentNum; i++)
	{
		if ((ManyStudents.Students + i)->Coordinate.X == 10 && (ManyStudents.Students + i)->Coordinate.Y == 10)
		{
			cout << "(10,10)�� �ִ� �л��� : " << (ManyStudents.Students + i)->Name << endl;
		}
	}
}


// �ʹ��� �ֹ��ϸ� ���ð� ���̰� ������ ���ð� �������.
// 1~10 ������ ���ڸ� �Է��ϸ� 1�� �ʹ���� 10�� �ʹ���� �ϳ��� ���̰�,
// 'E'�� �Է��ϸ� �� �� �ʹ��� �Ծ �ʹ� ���ð� �ϳ� �������.
// �Է��� ������ �׿��ִ� �ʹ��� �ַܼ� ���.

// ����ü �Ẹ��
struct Sushi
{
	int SushiNum;
	int Floor;
	int StackSize;
	int* Stack;
	
	Sushi()
	{

	}

	Sushi(int sushiNum, int present, int stack[], int size)
	{

	}
};

void Eat(int Stack[], int& Present, int InputNum);

void SushiGame()
{
	const int Max = 100;
	int Stack[Max] = { 0, };
	int Present = 0;
	int InputNum = 0;

	// Tick()
	do
	{
		// �ʹ� ���
		if (Present > 0)
		{
			cout << "���� �׿��ִ� �ʹ���" << endl;
			for (int i = 0; i < Present; i++)
			{
				cout << Stack[Present - i - 1] << endl;
			}
			cout << endl;
		}

		// �ʹ� �ױ�
		cout << "1~9�� �ʹ� �� ������. 0�� �ʹ��� �Խ��ϴ�." << endl;
		// InputNum �ʱ�ȭ
		InputNum = -1;
		//cin >> InputNum;
		InputNum = _getch() - 48; // ���� ���� �Է�. �ƽ�Ű�ڵ�� �������� ���� �ٲ���� �Ѵ�.
		if (InputNum < 10 && InputNum > 0)
		{
			Stack[Present] = InputNum;
			Present++;
		}
		else if (InputNum == 0)
		{
			Eat(Stack, Present, InputNum);
		}
		else
		{
			cout << "\n1~9 ������ ���� or 0�� �Է����ּ���." << endl;
		}

		// ȭ�� ����ϰ��ϱ�
		//system("cls");
		//cout << endl;

	} while (true);

	cout << "�ʹ� �ԱⰡ ����Ǿ����ϴ�." << endl;
}

void Eat(int Stack[], int &Present, int InputNum)
{
	if (Present <= 0)
	{
		cout << "\n���� �׿��ִ� �ʹ��� �����ϴ�." << endl;
	}
	else
	{
		cout << "\n" << Stack[--Present] << "�� �ʹ��� �Ծ����ϴ�." << endl;
		Stack[Present] = 0;
	}
}