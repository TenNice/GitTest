/*
#include <iostream>
#include <bitset>

#define number2 100; //데이터타입 쓰면 오류남. 얘는 할당되는게 아닌가본데?

using namespace std;

int main()
{
	
	int a = 0;
	int b = 0;
	int c = a & b;
	cout << "a & b = " << c << endl; //출력문 안에서 비트연산자 사용하면 인스턴스 찾을 수 없다면서 안 되네.

	long d = 0b11100001001011111111111111111001;
	int e = 0b11100001001011111111111111111001;
	cout << "bitset<64>(d) = " << bitset<64>(d) << endl;
	cout << "bitset<64>(e) = " << bitset<64>(e) << endl;

	a = 100;
	b = 30;
	cout << "a % b * 2 = " << a % b * 2 << endl; //%는 곱셈나눗셈이랑 연산 우선순위가 같네.
	

	//비트연산자는 성능상 이점(메모리 차지, 속도), 비트단위(로우레벨)이 필요한 경우에 쓴다.

	//철수가 과자 1000원 이하면 사고 비싸면 안 산다.
	int price = 0;
	int money = 10000;
	int snack = 1500;

	cout << "사고싶은 과자 가격 기준값을 입력하세요. 기준값보다 과자값이 저렴하면 구매합니다." << endl;
	cin >> price;

	if (snack < price)
	{
		cout << "과자(" << snack << "원)를 구매하여 지갑이 가벼워졌다." << endl;
		money -= snack;
		cout << "남은 돈은 " << money << "원입니다." << endl;
	}
	else
	{
		cout << "지갑을 지켜냈다! 집에 가자." << endl;
	}


	int score = 0;
	switch (score) //컨디션의 경우를 아래 case에 지정해서 컨디션의 값에 따라 해당되는 case 실행
	{
	case 10:
		cout << "10점" << endl;
	case 20:
		cout << "20점" << endl;
	default:
		cout << "모름" << endl;
	}
	


	//100이하의 홀수를 출력하기
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 1)
		{
			cout << i << " ";
		}
	}

	cout << "\n";

	int count = 0;
	while (count++ < 100)
	{
		if (count % 2 != 1)
		{
			continue;
		}
		cout << count << " ";
	}

	return 0;
}
*/