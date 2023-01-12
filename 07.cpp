/*
#include <iostream>

//랜덤함수를 위한 라이브러리들
#include <time.h>
#include <stdlib.h>

#include <ctime>

using namespace std;

//실습1
//3가지 정수를 받아서 최대값을 출력하는 함수
int max(int* Num)
{
	//int temp = 0;
	int result = 0;
	for (int i = 0; i < 3; i++)
	{
		//for (int j = 0; j <= i; j++)
		//{
		//	temp = Num[i]; //이렇게 안 하고 if안에 이걸 넣으면 num[i]가 자리가 바뀌었을 때 비교가 이상해진다.
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

//실습2
//2가지 정수를 받아서 변수에 값을 저장하고, 값을 교체하는 함수
//예를 들면 A = 100, B = 50 -> A = 50, B = 100. 스왑!
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Swap2(int *PtrA, int *PtrB) //int *PtrA = &A;   int *PtrB = &B;   이렇게 생각하자
{
	int temp = *PtrA;
	*PtrA = *PtrB;
	*PtrB = temp;
}

//실습3
//어떤 정수를 받아서 각 자리의 합을 구하는 함수
//입력 123 -> 결과 1+2+3해서 6 출력
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

//실습4
//주사위를 N번 던졌을 때 나오는 눈의 수를 각각 출력하는 프로그램
void Dice(int N)
{
	int num[6] = { 0, };

	srand(time(NULL)); //시드를 계속 호출하면 난수 계산할 때 호출된게 안 남아서? randO()에서 계속 같은 난수가 호출된다.

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
	
	cout << "주사위를 " << N << "번 굴렸을 때 결과" << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << "주사위 " << i + 1 << " : " << num[i] << endl;
	}

}

//실습5
//이자 계산기. 은행 예금 X를 저축했을 때 단리, 복리에 의한 이자가 얼마인지 출력하는 프로그램
//단리 : 원금 * 이자율 * 기간
//복리 : (원금 + (원금*이자율)) * 이자율
//입력 : 원금, 이자율, 기간
void Money(long double Principle, long double InterestRate, int Month)
{
	long double simpleInterest = 0;
	long double compoundInterest = 0;
	long double interest = InterestRate / 100;
	
	//단리
	simpleInterest = Month * (Principle * interest);

	//복리
	long double temp = Principle;
	for (int i = 0; i < Month; i++)
	{
		temp += temp * interest;
	}
	compoundInterest = temp - Principle;

	cout.precision(33);
	cout << "\n단리 이자는 : " << simpleInterest << "원입니다." << endl;
	cout.precision(33);
	cout << "단리 총 금액은 : " << Principle + simpleInterest << "원입니다." << endl << endl;
	cout.precision(33);
	cout << "복리 이자는 : " << compoundInterest << "원입니다." << endl;
	cout.precision(33);
	cout << "복리 총 금액은 : " << Principle + compoundInterest << "원입니다." << endl;
}

//실습6
//팩토리얼 구현
int Factorial(int N)
{
	int result = 1;
	for (int i = 0; i < N; i++)
	{
		result *= N - i;
	}

	return result;
}

//실습6-1
//재귀함수로 팩토리얼 구현
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

//실습6-2
//재귀함수로 등차수열 합 구하기
int OrdinalSequence(int N)
{
	if (N > 1)
		return N + OrdinalSequence(N - 1);
	else
		return 1;
}

//실습7
//피보나치 수열
//F(N) = F(N-1) + F(N-2)
int Fibonacci(int N)
{
	//if (N > 2)
	//	return Fibonacci(N - 1) + Fibonacci(N - 2);
	//else
	//	return 1;

	return N > 2 ? Fibonacci(N - 1) + Fibonacci(N - 2) : 1;
}

//실습7-1
//피보나치 수열 재귀함수 사용 안 하고 구하기
int Fibo(int N)
{
	int num1 = 1, num2 = 1, numN = 1;

	//앞과 앞앞의 값을 한 칸씩 밀어 다음 값을 저장시킨다는 아이디어
	for (int i = 0; i < N - 2; i++) //N-2번 반복 실행
	{
		num1 = num2;
		num2 = numN;
		numN = num1 + num2;
	}
	return numN;
}

//실습8
//배열의 최소값 구하기
int FindMin(int* NumberArray, int ArraySize) //int* NumberArray은 int NumberArray[]랑 같다.
{
	int Result = *NumberArray;
	for (int i = 0; i < ArraySize; i++)
	{
		if (Result > NumberArray[i])
		{
			//Result = NumberArray[i];
			Result = *(NumberArray + i); //오 이렇게도 사용 가능하네. +i번째 주소로 건너뛰어라. 1번 건너뛰는건 해당 자료형의 바이트 수만큼 건너뛴다.
		}
	}

	return Result;
}


int main()
{
	//int num[3];
	//cout << "정수 3개를 입력해주세요." << endl;
	//cin >> num[0] >> num[1] >> num[2];
	//cout << "입력한 정수 중 최대값은 : " << max(num);

	//int num2[2];
	//cout << "숫자 2개를 입력해주세요." << endl;
	//cin >> num2[0] >> num2[1];
	//Swap(num2[0], num2[1]);
	//cout << num2[0] << " " << num2[1] << endl;

	//int inputNum;
	//cout << "정수를 입력해주세요." << endl;
	//cin >> inputNum;
	//cout << "입력한 정수의 각 자리수의 합은 : " << SpecialAdd(inputNum) << endl;

	//cout << "주사위를 몇 번 굴릴지 입력해주세요." << endl;
	//int a = 0;
	//cin >> a;
	//Dice(a);

	//cout << "이자 계산기 입니다." << endl;
	//cout << "원금(원), 이자율(%), 기간(month)을 입력해주세요." << endl;
	//long double inputPrinciple, inputInterestRate;
	//int inputMonth;
	//cin >> inputPrinciple >> inputInterestRate >> inputMonth;
	//Money(inputPrinciple, inputInterestRate, inputMonth);

	//cout << "팩토리얼을 구할 정수를 입력해주세요." << endl;
	//int n;
	//cin >> n;
	//cout << "\n입력한 정수의 팩토리얼 값은 : " << Factorial(n) << endl;
	//cout << RFact(n) << endl;
	//cout << "\n1부터 입력한 정수까지의 합은 : " << OrdinalSequence(n) << endl;

	////---------피보나치 Start---------
	//clock_t start, finish;
	//double duration;
	//start = clock();

	//cout << "피보나치수열을 구합니다. 몇 번째 값을 구하고 싶은지 입력해주세요(정수)." << endl;
	//int inputN;
	//cin >> inputN;
	//cout << "\n[재귀함수 Version] 피보나치수열 " << inputN << "번째 값은 " << Fibonacci(inputN) << endl;

	//finish = clock();
	//duration = (double)(finish - start) / CLOCKS_PER_SEC;
	//cout.precision(33);
	//cout << duration << "초" << endl;
	////-------피보나치 버전 변경-------
	//start = clock();

	//cout << "\n[재귀함수 아닌 Version] 피보나치수열 " << inputN << "번째 값은 " << Fibo(inputN) << endl;

	//finish = clock();
	//duration = (double)(finish - start) / CLOCKS_PER_SEC;
	//cout.precision(33);
	//cout << duration << "초" << endl;
	////----------피보나치 End----------

	//int A = 1;
	//int B = 2;
	//cout << "변경 전 : " << A << ", " << B << endl;
	//Swap2(&A, &B);
	//cout << "변경 후 : " << A << ", " << B << endl;
	//int* PtrA = &A; //PtrA는 포인터 변수야. = &A 이거는 A의 주소값을 넣겠다. PtrA의 값은 &A라는 0F000B1 서울광역시 강남구
	//int* PtrB = &B;
	//Swap(A, B);
	//cout << "변경 후 : " << A << ", " << B << endl;

	int Array[] = { 23,456,2,457,456,345,376,768,3,1 };
	int ArrayLength = sizeof(Array) / 4; //sizeof함수는 배열이 메모리에서 차지하는 바이트 수를 알려주네
	cout << "{ 23,456,2,457,456,345,376,768,3,1 }에서 최소값은 " << FindMin(Array, ArrayLength) << endl;

	return 0;
}
*/