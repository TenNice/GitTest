#pragma once
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// 문자열을 역순으로 반환하는 함수 구현. 원본을 다른 배열에 저장하려면 결국에는 저장될 배열도 받아야하네
void Reverse(char* PtrCharacter, char *Out, int Size)
{
	// 원본을 유지하기 위한 몸부림
	for (int i = 0; i < Size; i++)
	{
		*(Out + i) = *(PtrCharacter + i);
	}

	// 캐릭터 배열을 받아서 다른 배열에 역순으로 저장 후 그걸 리턴하던가 아님 temp에 값 하나씩 넣어서 바꿔주던가
	// 2번째 방안으로 가자 -> 이 방법으로 했다가 원본 유지해야한다는 말에 Out 포인터를 받게 됐다ㅠ 이럴거면 첨부터 char* Reverse로 함수를 선언해서 Char형 포인터 반환하게 할 걸
	char temp;
	for (int i = 0; i < Size - i - 1; i++)
	{
		temp = *(PtrCharacter + i);
		*(PtrCharacter + i) = *(PtrCharacter + (Size - i - 1));
		*(PtrCharacter + (Size - i - 1)) = temp;
	}
}

// for(int i = 0; i < Size / 2; i++) //그냥 반만큼 반복하셨네
// Reverse함수 안에 자리 바꾸는 부분은 Swap으로 구현해보자. Call by Reference 활용해서




// 대미지 계산기. 함수 호출 끝나고 체력이 닳도록
// 계산식 : 대미지에서 방어력을 뺀만큼 체력이 줄어든다. 근데 회피율만큼 회피하는 경우도 있다.
void TakeDamage(float &Health, float Damage, float Armor, int DodgeRate)
{
	//int Rand = rand() % 100; // %100으로 하면 최대 99라서 회피율을 99.x%로 입력하면 무조건 회피한다 -> 회피율은 정수만 입력받게 했다. 애초에 rand()가 정수값으로 나오네.
	//RAND_MAX를 이용하면 99.5% 회피율 같은 것도 커버 가능하다. (double)rand() / RAND_MAX. int와 int로 나누면 소수가 버려지니까 형변환이 필요한데 둘 중 하나만 형변환 해주면 된다.
	float NewRand = ((float)rand() / RAND_MAX) * 100; // RAND_MAX는 미리 정의된 rand()함수의 최대값이다
	//cout << "Rand : " << Rand << endl;
	cout << "NewRand : " << NewRand << endl;

	// 대미지가 방어력보다 낮은지 체크
	if (Armor > Damage)
	{
		cout << "대미지를 입지 않았습니다." << endl;
	}
	else
	{
		// 회피율이 Rand보다 높거나 같으면 대미지를 입지않는다.
		Health = NewRand < DodgeRate ? Health : (Health - (Damage - Armor));
		if (NewRand < DodgeRate)
			cout << "회피했습니다!" << endl;
	}
}

// Swap함수(포인터 버전)
void Swap1(int* InputNum1, int* InputNum2)
{
	int temp = *InputNum1;
	*InputNum1 = *InputNum2;
	*InputNum2 = temp;
}


// Swap함수(레퍼런스 버전)
void Swap2(int &InputNum1, int &InputNum2)
{
	int temp = InputNum1;
	InputNum1 = InputNum2;
	InputNum2 = temp;
}

// Swap함수(포인터가 가리키는 대상을 바꾸는거 포인터 버전)
void SwapPointer1(int** InputNum1, int** InputNum2)
{
	int* temp = *InputNum1;
	*InputNum1 = *InputNum2;
	*InputNum2 = temp;
}

// Swap함수(포인터가 가리키는 대상을 바꾸는거 레퍼런스 버전)
void SwapPointer2(int* &InputNum1, int* &InputNum2)
{
	int* temp = InputNum1;
	InputNum1 = InputNum2;
	InputNum2 = temp;
}