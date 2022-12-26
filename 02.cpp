#include <iostream>
#include <bitset> //bitset 써볼려고.
using namespace std;

/*
int main()
{
	
	//비트연산자. & and. | or.
	const int a = 0b100;
	int b = 0b010; //0b를 앞에 붙이면 2진법이라는 뜻. 비트로 표현하겠다.
	const int c = a & b;
	const int d = a | b;
	const int e = ~b;
	const int f = b >> 1; //1칸 오른쪽으로 쉬프트. >>를 <<로 바꾸면 왼쪽으로 쉬프트. 4bit기준 만약 0001에 오른쪽으로 쉬프트 하면 1000 됨.

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "bitset<8>(a) = " << bitset<8>(a) << endl;
	cout << "bitset<8>(b) = " << bitset<8>(b) << endl;
	cout << "a & b = " << bitset<8>(c) << endl; //bit끼리 비교한거. a, b에서 같은 자리에 둘 다 1인 비트가 없어서 다 0으로 결과가 나왔다.
	cout << "a | b = " << bitset<8>(d) << endl;
	cout << "~b = " << bitset<8>(e) << endl;
	cout << "(b >> 1) = " << bitset<8>(f) << endl;
	//cout << "bitset<32>(b) = " << bitset<32>(b) << endl; //32비트로 변환하겠다. 00000000000000000000000000000010.
	

	int appleNumber = 100;
	int number = 1;
	cout << number << endl;

	number += appleNumber; //number = number + appleNumber;
	cout << "number = " << number << endl;

	cout << "number++ = " << number++ << endl; //number출력하고 +1
	cout << "++number = " << ++number << endl; //number +1하고 출력

	cout << "number-- = " << number-- << endl;
	cout << "--number = " << --number << endl;

	number /= 2;
	cout << number << endl;

	number |= 1;
	cout << number << " " << bitset<8>(number) << endl;

	return 0;
}
*/