/*
#include <iostream>
#include <bitset>

#define number2 100; //������Ÿ�� ���� ������. ��� �Ҵ�Ǵ°� �ƴѰ�����?

using namespace std;

int main()
{
	
	int a = 0;
	int b = 0;
	int c = a & b;
	cout << "a & b = " << c << endl; //��¹� �ȿ��� ��Ʈ������ ����ϸ� �ν��Ͻ� ã�� �� ���ٸ鼭 �� �ǳ�.

	long d = 0b11100001001011111111111111111001;
	int e = 0b11100001001011111111111111111001;
	cout << "bitset<64>(d) = " << bitset<64>(d) << endl;
	cout << "bitset<64>(e) = " << bitset<64>(e) << endl;

	a = 100;
	b = 30;
	cout << "a % b * 2 = " << a % b * 2 << endl; //%�� �����������̶� ���� �켱������ ����.
	

	//��Ʈ�����ڴ� ���ɻ� ����(�޸� ����, �ӵ�), ��Ʈ����(�ο췹��)�� �ʿ��� ��쿡 ����.

	//ö���� ���� 1000�� ���ϸ� ��� ��θ� �� ���.
	int price = 0;
	int money = 10000;
	int snack = 1500;

	cout << "������ ���� ���� ���ذ��� �Է��ϼ���. ���ذ����� ���ڰ��� �����ϸ� �����մϴ�." << endl;
	cin >> price;

	if (snack < price)
	{
		cout << "����(" << snack << "��)�� �����Ͽ� ������ ����������." << endl;
		money -= snack;
		cout << "���� ���� " << money << "���Դϴ�." << endl;
	}
	else
	{
		cout << "������ ���ѳ´�! ���� ����." << endl;
	}


	int score = 0;
	switch (score) //������� ��츦 �Ʒ� case�� �����ؼ� ������� ���� ���� �ش�Ǵ� case ����
	{
	case 10:
		cout << "10��" << endl;
	case 20:
		cout << "20��" << endl;
	default:
		cout << "��" << endl;
	}
	


	//100������ Ȧ���� ����ϱ�
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