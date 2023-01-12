/*
#include <iostream>

//�����Լ��� ���� ���̺귯����
#include <time.h>
#include <stdlib.h>

#include <ctime>

using namespace std;

//�ǽ�1
//3���� ������ �޾Ƽ� �ִ밪�� ����ϴ� �Լ�
int max(int* Num)
{
	//int temp = 0;
	int result = 0;
	for (int i = 0; i < 3; i++)
	{
		//for (int j = 0; j <= i; j++)
		//{
		//	temp = Num[i]; //�̷��� �� �ϰ� if�ȿ� �̰� ������ num[i]�� �ڸ��� �ٲ���� �� �񱳰� �̻�������.
		//	if (temp < Num[i - j])
		//	{
		//		Num[i] = Num[i - j];
		//		Num[i - j] = temp;
		//	}
		//}

		if (result < Num[i])
			result = Num[i];
	}

	// result = Num[2];

	return result;
}

//�ǽ�2
//2���� ������ �޾Ƽ� ������ ���� �����ϰ�, ���� ��ü�ϴ� �Լ�
//���� ��� A = 100, B = 50 -> A = 50, B = 100. ����!
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Swap2(int *PtrA, int *PtrB) //int *PtrA = &A;   int *PtrB = &B;   �̷��� ��������
{
	int temp = *PtrA;
	*PtrA = *PtrB;
	*PtrB = temp;
}

//�ǽ�3
//� ������ �޾Ƽ� �� �ڸ��� ���� ���ϴ� �Լ�
//�Է� 123 -> ��� 1+2+3�ؼ� 6 ���
int SpecialAdd(int a)
{
	int temp;
	int result = 0;
	while (1)
	{
		temp = (a % 10);
		a /= 10;
		result += temp;
		cout << temp << " ";
		if (a <= 0)
			break;
	}
	
	return result;
}

//�ǽ�4
//�ֻ����� N�� ������ �� ������ ���� ���� ���� ����ϴ� ���α׷�
void Dice(int N)
{
	int num[6] = { 0, };

	srand(time(NULL)); //�õ带 ��� ȣ���ϸ� ���� ����� �� ȣ��Ȱ� �� ���Ƽ�? randO()���� ��� ���� ������ ȣ��ȴ�.

	for (int i = 0; i < N; i++)
	{
		int random = (rand() % 6);

		switch (random)
		{
		case 0:
			num[0]++;
			break;
		case 1:
			num[1]++;
			break;
		case 2:
			num[2]++;
			break;
		case 3:
			num[3]++;
			break;
		case 4:
			num[4]++;
			break;
		case 5:
			num[5]++;
			break;
		default:
			break;
		}

	}
	
	cout << "�ֻ����� " << N << "�� ������ �� ���" << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << "�ֻ��� " << i + 1 << " : " << num[i] << endl;
	}

}

//�ǽ�5
//���� ����. ���� ���� X�� �������� �� �ܸ�, ������ ���� ���ڰ� ������ ����ϴ� ���α׷�
//�ܸ� : ���� * ������ * �Ⱓ
//���� : (���� + (����*������)) * ������
//�Է� : ����, ������, �Ⱓ
void Money(long double Principle, long double InterestRate, int Month)
{
	long double simpleInterest = 0;
	long double compoundInterest = 0;
	long double interest = InterestRate / 100;
	
	//�ܸ�
	simpleInterest = Month * (Principle * interest);

	//����
	long double temp = Principle;
	for (int i = 0; i < Month; i++)
	{
		temp += temp * interest;
	}
	compoundInterest = temp - Principle;

	cout.precision(33);
	cout << "\n�ܸ� ���ڴ� : " << simpleInterest << "���Դϴ�." << endl;
	cout.precision(33);
	cout << "�ܸ� �� �ݾ��� : " << Principle + simpleInterest << "���Դϴ�." << endl << endl;
	cout.precision(33);
	cout << "���� ���ڴ� : " << compoundInterest << "���Դϴ�." << endl;
	cout.precision(33);
	cout << "���� �� �ݾ��� : " << Principle + compoundInterest << "���Դϴ�." << endl;
}

//�ǽ�6
//���丮�� ����
int Factorial(int N)
{
	int result = 1;
	for (int i = 0; i < N; i++)
	{
		result *= N - i;
	}

	return result;
}

//�ǽ�6-1
//����Լ��� ���丮�� ����
int RFact(int N)
{
	if (N <= 1)
	{
		cout << "1 = ";
		return 1;
	}
	
	cout << N << "*";
	return N * RFact(N - 1);
}

//�ǽ�6-2
//����Լ��� �������� �� ���ϱ�
int OrdinalSequence(int N)
{
	if (N > 1)
		return N + OrdinalSequence(N - 1);
	else
		return 1;
}

//�ǽ�7
//�Ǻ���ġ ����
//F(N) = F(N-1) + F(N-2)
int Fibonacci(int N)
{
	//if (N > 2)
	//	return Fibonacci(N - 1) + Fibonacci(N - 2);
	//else
	//	return 1;

	return N > 2 ? Fibonacci(N - 1) + Fibonacci(N - 2) : 1;
}

//�ǽ�7-1
//�Ǻ���ġ ���� ����Լ� ��� �� �ϰ� ���ϱ�
int Fibo(int N)
{
	int num1 = 1, num2 = 1, numN = 1;

	//�հ� �վ��� ���� �� ĭ�� �о� ���� ���� �����Ų�ٴ� ���̵��
	for (int i = 0; i < N - 2; i++) //N-2�� �ݺ� ����
	{
		num1 = num2;
		num2 = numN;
		numN = num1 + num2;
	}
	return numN;
}

//�ǽ�8
//�迭�� �ּҰ� ���ϱ�
int FindMin(int* NumberArray, int ArraySize) //int* NumberArray�� int NumberArray[]�� ����.
{
	int Result = *NumberArray;
	for (int i = 0; i < ArraySize; i++)
	{
		if (Result > NumberArray[i])
		{
			//Result = NumberArray[i];
			Result = *(NumberArray + i); //�� �̷��Ե� ��� �����ϳ�. +i��° �ּҷ� �ǳʶپ��. 1�� �ǳʶٴ°� �ش� �ڷ����� ����Ʈ ����ŭ �ǳʶڴ�.
		}
	}

	return Result;
}


int main()
{
	//int num[3];
	//cout << "���� 3���� �Է����ּ���." << endl;
	//cin >> num[0] >> num[1] >> num[2];
	//cout << "�Է��� ���� �� �ִ밪�� : " << max(num);

	//int num2[2];
	//cout << "���� 2���� �Է����ּ���." << endl;
	//cin >> num2[0] >> num2[1];
	//Swap(num2[0], num2[1]);
	//cout << num2[0] << " " << num2[1] << endl;

	//int inputNum;
	//cout << "������ �Է����ּ���." << endl;
	//cin >> inputNum;
	//cout << "�Է��� ������ �� �ڸ����� ���� : " << SpecialAdd(inputNum) << endl;

	//cout << "�ֻ����� �� �� ������ �Է����ּ���." << endl;
	//int a = 0;
	//cin >> a;
	//Dice(a);

	//cout << "���� ���� �Դϴ�." << endl;
	//cout << "����(��), ������(%), �Ⱓ(month)�� �Է����ּ���." << endl;
	//long double inputPrinciple, inputInterestRate;
	//int inputMonth;
	//cin >> inputPrinciple >> inputInterestRate >> inputMonth;
	//Money(inputPrinciple, inputInterestRate, inputMonth);

	//cout << "���丮���� ���� ������ �Է����ּ���." << endl;
	//int n;
	//cin >> n;
	//cout << "\n�Է��� ������ ���丮�� ���� : " << Factorial(n) << endl;
	//cout << RFact(n) << endl;
	//cout << "\n1���� �Է��� ���������� ���� : " << OrdinalSequence(n) << endl;

	////---------�Ǻ���ġ Start---------
	//clock_t start, finish;
	//double duration;
	//start = clock();

	//cout << "�Ǻ���ġ������ ���մϴ�. �� ��° ���� ���ϰ� ������ �Է����ּ���(����)." << endl;
	//int inputN;
	//cin >> inputN;
	//cout << "\n[����Լ� Version] �Ǻ���ġ���� " << inputN << "��° ���� " << Fibonacci(inputN) << endl;

	//finish = clock();
	//duration = (double)(finish - start) / CLOCKS_PER_SEC;
	//cout.precision(33);
	//cout << duration << "��" << endl;
	////-------�Ǻ���ġ ���� ����-------
	//start = clock();

	//cout << "\n[����Լ� �ƴ� Version] �Ǻ���ġ���� " << inputN << "��° ���� " << Fibo(inputN) << endl;

	//finish = clock();
	//duration = (double)(finish - start) / CLOCKS_PER_SEC;
	//cout.precision(33);
	//cout << duration << "��" << endl;
	////----------�Ǻ���ġ End----------

	//int A = 1;
	//int B = 2;
	//cout << "���� �� : " << A << ", " << B << endl;
	//Swap2(&A, &B);
	//cout << "���� �� : " << A << ", " << B << endl;
	//int* PtrA = &A; //PtrA�� ������ ������. = &A �̰Ŵ� A�� �ּҰ��� �ְڴ�. PtrA�� ���� &A��� 0F000B1 ���ﱤ���� ������
	//int* PtrB = &B;
	//Swap(A, B);
	//cout << "���� �� : " << A << ", " << B << endl;

	int Array[] = { 23,456,2,457,456,345,376,768,3,1 };
	int ArrayLength = sizeof(Array) / 4; //sizeof�Լ��� �迭�� �޸𸮿��� �����ϴ� ����Ʈ ���� �˷��ֳ�
	cout << "{ 23,456,2,457,456,345,376,768,3,1 }���� �ּҰ��� " << FindMin(Array, ArrayLength) << endl;

	return 0;
}
*/