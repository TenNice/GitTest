/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num1;
	int num[10];
	cout << "Mem Size : " << sizeof(num1) << endl; //sizeof�Լ��� �޸𸮻󿡼� �����ϴ� ����(�� ����Ʈ) ����Ѵ�.
	cout << "Mem Size : " << sizeof(num) << endl;

	//5���� ��������� �迭�� �̿��Ͽ� ���ϱ�
	cout << "������ ���� �Է��ϼ���." << endl;
	int number = 0;
	cin >> number;

	int total = 0;
	vector<int> score; //intŸ�� ���� ����.
	cout << "������ ������ �Է��ϼ���." << endl;

	int temp;
	for (int i = 0; i < number; i++)
	{
		cin >> temp;
		score.push_back(temp); //������ ���� ����ĭ�� temp�� �Ҵ�.
		total += score[i]; //���Ͱ��� ������ �迭ó�� ����.
	}

	double result = (double)total / (double)number;
	cout.precision(10); //�����κ��̶� �Ҽ��κ� ���ļ� 10�� ǥ���Ѵٴ� ��
	cout << "������ ��������� " << result << endl;

	return 0;
}
*/