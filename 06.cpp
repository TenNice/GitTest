/*
#include <iostream>

using namespace std;

int main()
{
	//���� + - - * / %
	//����� ����ϰ� �����Ͻðڽ��ϱ� ���� (Y/N)
	
	int inputNum[100] = { 0, };
	char inputCal[100];
	char question = 'Y';

	do {
		cout << "����ϰ� ���� �������� �Է����ּ���(�����ڴ� + - * / %)" << endl;

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
				cout << "\n����ε� �����ڸ� �Է����ּ���." << endl;
				break;
			}
			i++;
		}
		
		cout << result << endl;
		cout << "�����Ͻðڽ��ϱ�? (Y/N)" << endl;
		cin >> question;

	} while (question != 'Y');
	

	return 0;
}
*/