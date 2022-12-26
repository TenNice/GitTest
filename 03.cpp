#include <iostream>

using namespace std;

/*
int main()
{
	
	int number = 1;
	number += 100;

	int i = 0;
	bool t = i < 10000; //bool타입은 조건문을 할당할 수도 있네.
	cout << number << endl;
	cout << "bool t = " << t << endl;

	while (t) //()안 조건을 컨디션이라고 하나보네. 내용은 바디.
	{
		i++;
		t = i < 10000;
		number++;
	}
	cout << "반복문 후 number = " << number << endl;
	

	int count = 0;
	while (count++ < 10) //조건 체크 후 +1
	{
		cout << count << "번째" << endl; //1부터 찍히네
	}

	for (; count < 10; count++) //처음 칸에서 변수 초기화 안 해도 되네? 이미 선언된거 사용하면.
	{
		cout << "Hi" << endl;
	}

	do {
		//바디 내용.
	} while (count < 10);
	

	//1부터 100까지 더한 결과를 출력하기
	int result1 = 0;
	for (int i = 0; i <= 100; i++)
	{
		result1 += i;
	}
	cout << "result1 = " << result1 << endl;

	int result2 = 0;
	int count = 0;
	while (count++ < 100)
	{
		result2 += count; //여기있는 count는 while조건에 있는 count보다 1크다!
	}
	cout << "result2 = " << result2 << endl;

	int result3 = 0;
	int count2 = 0;
	do {
		result3 += count2;
	} while (count2++ < 100);
	cout << "result3 = " << result3 << endl;


	//별찍기 문제
	int inputNum;
	cout << "정수값을 입력하세요" << endl;
	cin >> inputNum;

	int countTree = 0;
	do {
		int countTree2 = 0;
		do {
			cout << "*";
		} while (++countTree2 <= countTree);
		cout << endl;
	} while (++countTree < inputNum);

	int whileCount = 0;
	while (whileCount++ < inputNum)
	{
		int whileCount2 = 0;
		while (whileCount2++ < whileCount) //while조건문 whileCount보다 1 크다!
		{
			cout << "*";
		}
		cout << endl;
	}

	for (int i = 0; i < inputNum; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}


	return 0;
}
*/