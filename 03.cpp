#include <iostream>

using namespace std;

/*
int main()
{
	
	int number = 1;
	number += 100;

	int i = 0;
	bool t = i < 10000; //boolŸ���� ���ǹ��� �Ҵ��� ���� �ֳ�.
	cout << number << endl;
	cout << "bool t = " << t << endl;

	while (t) //()�� ������ ������̶�� �ϳ�����. ������ �ٵ�.
	{
		i++;
		t = i < 10000;
		number++;
	}
	cout << "�ݺ��� �� number = " << number << endl;
	

	int count = 0;
	while (count++ < 10) //���� üũ �� +1
	{
		cout << count << "��°" << endl; //1���� ������
	}

	for (; count < 10; count++) //ó�� ĭ���� ���� �ʱ�ȭ �� �ص� �ǳ�? �̹� ����Ȱ� ����ϸ�.
	{
		cout << "Hi" << endl;
	}

	do {
		//�ٵ� ����.
	} while (count < 10);
	

	//1���� 100���� ���� ����� ����ϱ�
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
		result2 += count; //�����ִ� count�� while���ǿ� �ִ� count���� 1ũ��!
	}
	cout << "result2 = " << result2 << endl;

	int result3 = 0;
	int count2 = 0;
	do {
		result3 += count2;
	} while (count2++ < 100);
	cout << "result3 = " << result3 << endl;


	//����� ����
	int inputNum;
	cout << "�������� �Է��ϼ���" << endl;
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
		while (whileCount2++ < whileCount) //while���ǹ� whileCount���� 1 ũ��!
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