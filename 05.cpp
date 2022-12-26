/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num1;
	int num[10];
	cout << "Mem Size : " << sizeof(num1) << endl; //sizeof함수는 메모리상에서 차지하는 공간(몇 바이트) 계산한다.
	cout << "Mem Size : " << sizeof(num) << endl;

	//5과목 평균점수를 배열을 이용하여 구하기
	cout << "과목의 수를 입력하세요." << endl;
	int number = 0;
	cin >> number;

	int total = 0;
	vector<int> score; //int타입 벡터 선언.
	cout << "과목의 점수를 입력하세요." << endl;

	int temp;
	for (int i = 0; i < number; i++)
	{
		cin >> temp;
		score.push_back(temp); //벡터의 가장 뒤쪽칸에 temp값 할당.
		total += score[i]; //벡터값의 접근은 배열처럼 가능.
	}

	double result = (double)total / (double)number;
	cout.precision(10); //정수부분이랑 소수부분 합쳐서 10개 표현한다는 뜻
	cout << "과목의 평균점수는 " << result << endl;

	return 0;
}
*/