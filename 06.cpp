/*
#include <iostream>

using namespace std;

int main()
{
	//계산기 + - - * / %
	//계산결과 출력하고 종료하시겠습니까 질문 (Y/N)
	
	int inputNum[100] = { 0, };
	char inputCal[100];
	char question = 'Y';

	do {
		cout << "계산하고 싶은 정수값을 입력해주세요(연산자는 + - * / %)" << endl;

		int result = 0;

		int count = 0;
		while(inputCal[count-1] != '=') {
			cin >> inputNum[count] >> inputCal[count];
			cout << inputNum[count] << inputCal[count];
			count++;
		}

		result = inputNum[0];
		int i = 0;
		while (inputCal[i] != '=') {
			switch (inputCal[i]) {
			case '+':
				result += inputNum[i + 1];
				break;
			case '-':
				result -= inputNum[i + 1];
				break;
			case '*':
				result *= inputNum[i + 1];
				break;
			case '/':
				result /= inputNum[i + 1];
				break;
			case '%':
				result %= inputNum[i + 1];
				break;
			case '=':
				break;
			default:
				cout << "\n제대로된 연산자를 입력해주세요." << endl;
				break;
			}
			i++;
		}
		
		cout << result << endl;
		cout << "종료하시겠습니까? (Y/N)" << endl;
		cin >> question;

	} while (question != 'Y');
	

	return 0;
}
*/