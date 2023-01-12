#pragma once
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// ���ڿ��� �������� ��ȯ�ϴ� �Լ� ����. ������ �ٸ� �迭�� �����Ϸ��� �ᱹ���� ����� �迭�� �޾ƾ��ϳ�
void Reverse(char* PtrCharacter, char *Out, int Size)
{
	// ������ �����ϱ� ���� ���θ�
	for (int i = 0; i < Size; i++)
	{
		*(Out + i) = *(PtrCharacter + i);
	}

	// ĳ���� �迭�� �޾Ƽ� �ٸ� �迭�� �������� ���� �� �װ� �����ϴ��� �ƴ� temp�� �� �ϳ��� �־ �ٲ��ִ���
	// 2��° ������� ���� -> �� ������� �ߴٰ� ���� �����ؾ��Ѵٴ� ���� Out �����͸� �ް� �ƴ٤� �̷��Ÿ� ÷���� char* Reverse�� �Լ��� �����ؼ� Char�� ������ ��ȯ�ϰ� �� ��
	char temp;
	for (int i = 0; i < Size - i - 1; i++)
	{
		temp = *(PtrCharacter + i);
		*(PtrCharacter + i) = *(PtrCharacter + (Size - i - 1));
		*(PtrCharacter + (Size - i - 1)) = temp;
	}
}

// for(int i = 0; i < Size / 2; i++) //�׳� �ݸ�ŭ �ݺ��ϼ̳�
// Reverse�Լ� �ȿ� �ڸ� �ٲٴ� �κ��� Swap���� �����غ���. Call by Reference Ȱ���ؼ�




// ����� ����. �Լ� ȣ�� ������ ü���� �⵵��
// ���� : ��������� ������ ����ŭ ü���� �پ���. �ٵ� ȸ������ŭ ȸ���ϴ� ��쵵 �ִ�.
void TakeDamage(float &Health, float Damage, float Armor, int DodgeRate)
{
	//int Rand = rand() % 100; // %100���� �ϸ� �ִ� 99�� ȸ������ 99.x%�� �Է��ϸ� ������ ȸ���Ѵ� -> ȸ������ ������ �Է¹ް� �ߴ�. ���ʿ� rand()�� ���������� ������.
	//RAND_MAX�� �̿��ϸ� 99.5% ȸ���� ���� �͵� Ŀ�� �����ϴ�. (double)rand() / RAND_MAX. int�� int�� ������ �Ҽ��� �������ϱ� ����ȯ�� �ʿ��ѵ� �� �� �ϳ��� ����ȯ ���ָ� �ȴ�.
	float NewRand = ((float)rand() / RAND_MAX) * 100; // RAND_MAX�� �̸� ���ǵ� rand()�Լ��� �ִ밪�̴�
	//cout << "Rand : " << Rand << endl;
	cout << "NewRand : " << NewRand << endl;

	// ������� ���º��� ������ üũ
	if (Armor > Damage)
	{
		cout << "������� ���� �ʾҽ��ϴ�." << endl;
	}
	else
	{
		// ȸ������ Rand���� ���ų� ������ ������� �����ʴ´�.
		Health = NewRand < DodgeRate ? Health : (Health - (Damage - Armor));
		if (NewRand < DodgeRate)
			cout << "ȸ���߽��ϴ�!" << endl;
	}
}

// Swap�Լ�(������ ����)
void Swap1(int* InputNum1, int* InputNum2)
{
	int temp = *InputNum1;
	*InputNum1 = *InputNum2;
	*InputNum2 = temp;
}


// Swap�Լ�(���۷��� ����)
void Swap2(int &InputNum1, int &InputNum2)
{
	int temp = InputNum1;
	InputNum1 = InputNum2;
	InputNum2 = temp;
}

// Swap�Լ�(�����Ͱ� ����Ű�� ����� �ٲٴ°� ������ ����)
void SwapPointer1(int** InputNum1, int** InputNum2)
{
	int* temp = *InputNum1;
	*InputNum1 = *InputNum2;
	*InputNum2 = temp;
}

// Swap�Լ�(�����Ͱ� ����Ű�� ����� �ٲٴ°� ���۷��� ����)
void SwapPointer2(int* &InputNum1, int* &InputNum2)
{
	int* temp = InputNum1;
	InputNum1 = InputNum2;
	InputNum2 = temp;
}