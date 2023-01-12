#pragma once

#include <conio.h> // _getch() 쓰려고

int FactorialLimited(int N)
{
	static int Cnt = 0; // 스태틱 영역에 생기는 로컬 변수라 접근은 이 함수 내에서만 가능. 저장된게 스태틱 영역인거
	bool bFirstCall = ++Cnt == 1; // ++Cnt == 1 이면 true가 들어가고 아니면 false가 들어가고

	// Cnt가 10이상인지 체크
	if (Cnt >= 10)
	{
		cout << "10번 이상 호출되어 중단합니다. 제대로된 결과값이 나오지 않았습니다." << endl;
		//cout << "Cnt : " << Cnt << endl;
		//Cnt = 0;
		return 1;
	}

	// 재귀함수 종료 조건
	else if (N <= 1)
	{
		//cout << "Cnt : " << Cnt << endl;
		//Cnt = 0;
		return 1;
	}
	
	// FirstCall인지 확인하려면 바로 리턴하면 안 되어서 Result에 결과값 담았다.
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

	Student(string name, int age, int mScore, int eScore) // Day day, Coordinate coordinate는 생성자에서 미리 못 받네??
	{
		Name = name;
		Age = age;
		MathScore = mScore;
		EngScore = eScore;
	}
};

// Student 구조체 타입의 배열을 가지고 있는 구조체
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
		cout << "(10,10)에 있는 학생은 : " << Student.Name << endl;
	}
}

void PrintLocation1(Student Student[], int StudentNum)
{
	for (int i = 0; i < StudentNum; i++)
	{
		if ((Student + i)->Coordinate.X == 10 && (Student + i)->Coordinate.Y == 10)
		{
			cout << "(10,10)에 있는 학생은 : " << (Student + i)->Name << endl;
		}
	//	if (Student[i].Coordinate.X == 10 && Student[i].Coordinate.Y == 10)
	//	{
	//		cout << "(10,10)에 있는 학생은 : " << Student[i].Name << endl;
	//	}
	}
}

void PrintLocation2(Club ManyStudents, int StudentNum)
{
	for (int i = 0; i < StudentNum; i++)
	{
		if ((ManyStudents.Students + i)->Coordinate.X == 10 && (ManyStudents.Students + i)->Coordinate.Y == 10)
		{
			cout << "(10,10)에 있는 학생은 : " << (ManyStudents.Students + i)->Name << endl;
		}
	}
}


// 초밥을 주문하면 접시가 쌓이고 먹으면 접시가 사라진다.
// 1~10 사이의 숫자를 입력하면 1번 초밥부터 10번 초밥까지 하나씩 쌓이고,
// 'E'를 입력하면 맨 위 초밥을 먹어서 초밥 접시가 하나 사라진다.
// 입력할 때마다 쌓여있는 초밥은 콘솔로 출력.

// 구조체 써보자
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
		// 초밥 출력
		if (Present > 0)
		{
			cout << "현재 쌓여있는 초밥은" << endl;
			for (int i = 0; i < Present; i++)
			{
				cout << Stack[Present - i - 1] << endl;
			}
			cout << endl;
		}

		// 초밥 쌓기
		cout << "1~9번 초밥 중 고르세요. 0은 초밥을 먹습니다." << endl;
		// InputNum 초기화
		InputNum = -1;
		//cin >> InputNum;
		InputNum = _getch() - 48; // 엔터 없이 입력. 아스키코드로 전해져서 값을 바꿔줘야 한다.
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
			cout << "\n1~9 사이의 숫자 or 0을 입력해주세요." << endl;
		}

		// 화면 깔끔하게하기
		//system("cls");
		//cout << endl;

	} while (true);

	cout << "초밥 먹기가 종료되었습니다." << endl;
}

void Eat(int Stack[], int &Present, int InputNum)
{
	if (Present <= 0)
	{
		cout << "\n현재 쌓여있는 초밥이 없습니다." << endl;
	}
	else
	{
		cout << "\n" << Stack[--Present] << "번 초밥을 먹었습니다." << endl;
		Stack[Present] = 0;
	}
}