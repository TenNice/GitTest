#pragma once
#include <iomanip>


enum class Days
{
	Mon,
	Tue,
	Wed,
	Thu,
	Fri,
	Sat,
	Sun,
};

enum class Color
{
	None,
	Red,
	Blue,
	Yellow,
	Green,
	White,
	Black,
};

enum class CharacterStatusFlags // Flag�� ������ ��Ʈ�� ǥ���Ѵٴ� ��. �̰��� ���� �ϳ��� ��Ʈ�� �ϳ��� ĳ���� ���¸� ��Ÿ����.
{
	None,
	Stun = 1 << 1, // 1�� �������� ����Ʈ 1��
	Dot = 1 << 2,
	Slow = 1 << 3,
	Dead = 1 << 4,
};

enum class HumanClass
{
	None,
	Magician,
	SwordMan,
	GunMan,
	Healer,
	Guardian,
	Enemy
};

class Coord
{
private:
	int X;
	int Y;
public:
	Coord()
	{
		X = 1;
		Y = 1;
	}
	Coord(int Num1, int Num2)
	{
		X = Num1;
		Y = Num2;
	}
	~Coord()
	{
		cout << "Coord Destroyed" << endl;
	}

	void ShowCoord()
	{
		cout << "X : " << X << ", " << "Y : " << Y << "\n";
	}
	void SetCoord(int Num1, int Num2)
	{
		X = Num1;
		Y = Num2;
	}
};

class People
{
private:
	int Secret;
	string Name; // ����� ���ο� ���� �� �ϸ� string �� ����. ��?
	int Age;
	Coord* PeopleCoord; // �޸� ���� �� ������?!
	People* Friends[100]; // People* Ÿ�� ���� 100���� ����� ��. People�ּҸ� 100�� ������ �� �ְ� �ȰŴ�. �Ʒ��� ���� �ǵ� ����� �̸� ���س����Ѵٴ°� ����
	People** AnotherFriends; // ���� People* Ÿ�� �迭�� ����� �ּҸ� �Ѱ��� ������
	int FCount = 0;
	int Money = 0;

public:
	// ���� ���� �Լ�. �̰� ������ �߻�ȭ�ȰŶ� ��ü ������ �Ұ����ϴ�
	//virtual void cry() = 0;
	virtual void cry()
	{
		cout << "Hi!" << endl;
	}

	People()
	{
		Name = "Default";
		Age = 1;
		Secret = 0;
		PeopleCoord = new Coord(); // PeopleCoord��� �ָ� �� ����� ����Լ��� ����Ϸ��� �ߴ��� ����� ���� �� �ߴ�. ���� ���� �Լ��� ����ؼ� �׷�������.
		PeopleCoord->SetCoord(1, 1);
		AnotherFriends = new People * [200];
		cout << "People Created" << endl;
	}
	People(string name)
	{
		Name = name;
		Age = 1;
		Secret = 0;
		PeopleCoord = new Coord();
		PeopleCoord->SetCoord(1, 1);
		AnotherFriends = new People * [200];
		cout << "People Created" << endl;
	}
	People(string name, int age)
	{
		Name = name;
		Age = age;
		Secret = 0;
		PeopleCoord = new Coord();
		PeopleCoord->SetCoord(1, 1);
		AnotherFriends = new People * [200];
		cout << "People Created" << endl;
	}
	People(string name, int age, Coord* coord)
	{
		Name = name;
		Age = age;
		Secret = 0;
		PeopleCoord = coord;
		AnotherFriends = new People * [200];
		cout << "People Created" << endl;
	}
	~People()
	{
		// ������������ Ȯ�� �� ����
		if (PeopleCoord != nullptr)
		{
			delete PeopleCoord;
		}
		if (AnotherFriends != nullptr)
		{
			delete AnotherFriends;
		}
		cout << "People Destroyed" << endl;
	}

	void Move()
	{
		cout << Name << "���� �̵��Ͽ����ϴ�." << endl;
	}
	void Speak()
	{
		cout << Name << " : ���ϴ� ��!" << endl;
	}
	void Eat()
	{
		cout << Name << "���� �Ļ����Դϴ�." << endl;
	}

	virtual void Print()
	{
		cout << "Name : " << Name << endl;
		cout << "Age : " << Age << endl;
	}

	string GetName()
	{
		return Name;
	}
	int GetAge()
	{
		return Age;
	}

	int GetFCount()
	{
		return FCount;
	}

	// �ڴܼ��� ���� ������Ű�� � ģ���� �߰��Ǿ����� �� ���� ���� �߰���Ű�� �Լ��� �� �ʿ�������.
	// �ٵ� People* Ÿ���� �޾� People* Ÿ�� �迭�� AnotherFriends�� �־��ָ� 
	void AddFriend(People* Friend)
	{
		if (AnotherFriends[FCount] != nullptr)
		{
			AnotherFriends[FCount++] = Friend; // FCount�� ����ִ� �ε����� ��ȣ�� ����Ű�� �Ǵ� ���̴�
		}
	}
	void RemoveFriend(People* Friend)
	{
		bool bCheck = false; // �Է¹��� ģ���� ģ������Ʈ�� �����ϴ��� Ȯ�� �� �����Ϸ��� ����
		 
		// ģ���� 0���̸� remove�� �ʿ䰡 ����
		if (FCount > 0)
		{
			int temp = -1; // ������ ģ�� �ε��� �����
			for (int i = 0; i < FCount; i++)
			{
				if (AnotherFriends[i]->Name == Friend->Name) // �̸��� ��ġ�� �ʴ´ٰ� ����(IDó��)
				{
					temp = i;
					delete Friend;

					// ģ�� ����Ʈ�� �Է��� ģ���� ������ true��
					bCheck = true;

					break;
				}
			}

			// for�� �� �������ϱ� �� üũ�ѰŰ�, ģ�� ����Ʈ�� ģ���� �������� ������ return
			if (bCheck != true)
			{
				cout << "�Է��� ģ���� ����Ʈ�� �������� �ʽ��ϴ�." << endl;
				return;
			}

			// ������ �ε������� �ڿ� ģ�� ������ 1ĭ�� ����
			for (int i = temp; i < FCount - 1; i++)
			{
				AnotherFriends[i] = AnotherFriends[i + 1];
			}

			// FCount 1 ���̱�
			--FCount;
		}
		else
		{
			cout << "ģ���� 0���Դϴ�." << endl;
		}
	}

};

class Character : public People
{
private:
	CharacterStatusFlags Status;
	int HP, MP;
	string Guild;
	HumanClass Class;

public:
	// �θ� ���� ���������Լ� �������̵�
	virtual void cry() override
	{
		cout << "�Լ�!" << endl;
	}

	Character()
	{
		HP = 100;
		MP = 100;
		Guild = "No Guild";
	}
	Character(int InputHP, int InputMP)
	{
		HP = InputHP;
		MP = InputMP;
		Guild = "No Guild";
	}
	Character(int InputHP, int InputMP, string InputGuild)
	{
		HP = InputHP;
		MP = InputMP;
		Guild = InputGuild;
	}
	Character(string InputGuild)
	{
		HP = 100;
		MP = 100;
		Guild = InputGuild;
	}
	// �θ� ������ �� ���ϴ°� ȣ��
	Character(string name, int age, string InputGuild) : People(name, age)
	{
		HP = 100;
		MP = 100;
		Guild = InputGuild;
	}

	virtual void Print() override
	{
		cout << "Name : " << GetName() << endl;
		cout << "Age : " << GetAge() << endl;
		cout << "Guild : " << Guild << endl;
	}

	CharacterStatusFlags GetStatus()
	{
		return Status;
	}

	string GetGuild()
	{
		return Guild;
	}
};

/*
class Enemy : public People
{
private:
	CharacterStatusFlags Status;
	int HP;
	string Drop;

public:
	// �θ� ���� ���������Լ� �������̵�
	virtual void cry() override
	{
		cout << "���" << endl;
	}

	Enemy()
	{
		HP = 100;
		Drop = "Nothing";
	}
	Enemy(int InputHP, string SpecialItem)
	{
		HP = InputHP;
		Drop = SpecialItem;
	}
	Enemy(string name, int age, int InputHP, string SpecialItem) : People(name, age)
	{
		HP = InputHP;
		Drop = SpecialItem;
	}

	virtual void Print() override
	{
		cout << "Name : " << GetName() << endl;
		cout << "Age : " << GetAge() << endl;
		cout << "Drop : " << Drop << endl;
	}

	CharacterStatusFlags GetStatus()
	{
		return Status;
	}
	string GetDrop()
	{
		return Drop;
	}
};
*/



// ���� �����
// ���� Ŭ������ ���� ��
// �������� ũ��� n*n�̰� n�� �Է¹޴´�.
// �� ���� ���� �ϼ��ؾ� �¸��ϴ����� ���ڸ� �Է¹޴´�. (�ִ� 2n+2���ڳ�)

// �ڡڡڡڡ��ϸ鼭 �� �����ڡڡڡڡ�
// Ŭ������ ��������� �����ߴ��� ���߰��� ���� �ʿ������� ������ �ִ�. �¸�����(�� ��). �갡 �̰ű��� ������ �־�� �ϳ�?
// Ŭ������ ����� ������ ������ �־�� �ϳ� �����ϱⰡ ���� �ʴ�. Ŭ���� ������ �� �Լ� �߿����� �긦 Ŭ������ ������ �׷��� ���� �͵� �ְ�.
// ��Ŭ���� ������ �� �Լ��� ������ Ŭ���� ���� ����Լ��� ��������� �����ϴ°� ���� ���� �� ����. �������� �������� �ʰ� �Ķ���ͷ� �ް� �ϴ°� ���� ������!

// Input
// Tick(). �Է� ó���� ����
// Rendering

// ���� �������� ����ϱ� enum�� Ȱ�� ���ϳ�
class Bingo
{
private:
	int BingoSize = 0;
	int WinLineNum = 0;
	int** BingoSpace;
	int* Check; // �Է¹��� ���� �ߺ����� Ȯ���ϱ� ���� üũ�� �迭

public:
	Bingo()
	{
		//int temp = 0;
		//cout << "�� ��¥�� �������� ���� ������ �Է����ּ���." << endl;
		//cin >> temp;
		//SetBingoSize(temp);
		//cout << "���� �� �� �ϼ��Ǿ�� �¸����� �Է����ּ���." << endl;
		//cin >> temp;
		//SetWinLineNum(temp);
		//CreateBingoSpace();
		//cout << "�������� �����Ǿ����ϴ�." << endl;
	}
	Bingo(int Size, int WinNum)
	{
		SetBingoSize(Size);
		SetWinLineNum(WinNum);
		CreateBingoSpace();
		CreateCheck(Size);
		cout << "�������� �����Ǿ����ϴ�." << endl;
	}
	~Bingo()
	{
		delete BingoSpace;
		delete Check;
		cout << "�������� �Ҹ�Ǿ����ϴ�." << endl;
	}

	void SetBingoSize(int Size)
	{
		BingoSize = Size;
	}
	int GetBingoSize()
	{
		return BingoSize;
	}

	void SetWinLineNum(int WinNum)
	{
		WinLineNum = WinNum;
	}
	int GetWinLineNum()
	{
		return WinLineNum;
	}

	// BingoSize * BingoSize ũ���� ������ ���� ����
	void CreateBingoSpace()
	{
		BingoSpace = new int* [BingoSize];
		for (int i = 0; i < BingoSize; i++)
		{
			BingoSpace[i] = new int[BingoSize];
		}
	}

	// ������� �����ǿ� ���� �Է¹ޱ�
	void SetBingoSpace()
	{
		// �����ϰ� ������
		// O(N^3)�� O(N^2)�� ���̱�
		// �Է��� ���� BingoSpace�� �ִ°� 2���� �迭�� �ִ°Ŷ� O^2

		bool bCheck; // �ߺ�üũ��

		cout << "�����ǿ� ���ڸ� �Է����ּ���(���ڴ� 1 �̻��̾�� �մϴ�)." << endl;
		for (int i = 0; i < BingoSize; i++)
		{
			for (int j = 0; j < BingoSize; j++)
			{
				cout << i * BingoSize + j + 1 << "��° ���� �Է�" << endl;
				cin >> BingoSpace[i][j];
				Check[i * BingoSize + j] = BingoSpace[i][j];

				bCheck = false;
				while (!bCheck)
				{
					// �ߺ����� üũ. for���� �� ����. �����ս� O(N^3).
					for (int k = 0; k < i * BingoSize + j; k++)
					{
						if (Check[k] == BingoSpace[i][j])
						{
							cout << "�ߺ��� �����Դϴ�. �ٽ� �Է����ּ���." << endl;
							cin >> BingoSpace[i][j];
							Check[i * BingoSize + j] = BingoSpace[i][j];
							k = -1; // �̰� �ٽ� for�ݺ������� ���� �ʱ�ȭ �κ��� ���õǰ� �ٷ� k++ �Ǵ°ǰ�?? 0�����ϱ� Check[0]�� üũ�� �� �ϳ�
						}
					}
					bCheck = true;
				} // End while
			} // End for(j)
		} // End for(i)
	} // End SetBingoSpace

	int GetBingoSpace(int x, int y)
	{
		return BingoSpace[x][y];
	}
	void RenewBingoSpace(int x, int y)
	{
		BingoSpace[x][y] = -1;
	}

	void CreateCheck(int size)
	{
		Check = new int[size * size];
		// 0���� �ʱ�ȭ
		for (int i = 0; i < size * size; i++)
		{
			Check[i] = 0;
		}
	}

};

// �Է��� ���� �ֳ� ã�� �Լ� ����
void FindNum(Bingo& bingo, int InputNum);

// ���� �� �� �ϼ��ƴ��� Ȯ���ϴ� �Լ� ����
int CountCompleteLine(Bingo& bingo);

// ���� ���� X�� �����ֱ� �Լ� ����
void ShowX(Bingo& Bingo1, Bingo& Bingo2);

void BingoGame()
{
	int InputBingoSize = 0, InputWinLineNum = 0;
	cout << "�� ��¥�� �������� ���� ������ �Է����ּ���." << endl;
	cin >> InputBingoSize;
	cout << "���� �� �� �ϼ��Ǿ�� �¸����� �Է����ּ���." << endl;
	cin >> InputWinLineNum;

	Bingo Bingo1 = Bingo(InputBingoSize, InputWinLineNum);
	Bingo Bingo2 = Bingo(InputBingoSize, InputWinLineNum);

	Bingo1.SetBingoSpace();
	Bingo2.SetBingoSpace();

	cout << endl;

	// Tick()
	while (true)
	{
		// ȭ�� ����ϰ��ϱ�
		system("cls");

		cout << "�¸��� �� �ִ� ���� ����(Goal) : " << InputWinLineNum << endl;
		cout << "Bingo1�� ���� ���� ���� : " << CountCompleteLine(Bingo1) << endl;
		cout << "Bingo2�� ���� ���� ���� : " << CountCompleteLine(Bingo2) << endl << endl;


		ShowX(Bingo1, Bingo2);


		int temp = 0;
		cout << "\n������ ���ڸ� �Է����ּ���." << endl;
		cin >> temp;

		// �������� ���� �� ���� ���ڰ� �ִٸ� -1��
		FindNum(Bingo1, temp);
		FindNum(Bingo2, temp);


		// �� ������ �¸� ���� ���� ���� Ȯ�� �� �¸� �� ��� ���
		if ((CountCompleteLine(Bingo1) >= Bingo1.GetWinLineNum()) && (CountCompleteLine(Bingo2) < Bingo2.GetWinLineNum()))
		{
			cout << "Bingo1�� �¸��Դϴ�!" << endl;
			cout << "Bingo1�� ���� ���� : " << CountCompleteLine(Bingo1) << endl;
			cout << "Bingo2�� ���� ���� : " << CountCompleteLine(Bingo2) << endl;
			break;
		}
		else if ((CountCompleteLine(Bingo2) >= Bingo2.GetWinLineNum()) && (CountCompleteLine(Bingo1) < Bingo1.GetWinLineNum()))
		{
			cout << "Bingo2�� �¸��Դϴ�!" << endl;
			cout << "Bingo1�� ���� ���� : " << CountCompleteLine(Bingo1) << endl;
			cout << "Bingo2�� ���� ���� : " << CountCompleteLine(Bingo2) << endl;
			break;
		}
		else if ((CountCompleteLine(Bingo2) >= Bingo2.GetWinLineNum()) && (CountCompleteLine(Bingo1) >= Bingo1.GetWinLineNum()))
		{
			cout << "���º��Դϴ�." << endl;
			cout << "Bingo1�� ���� ���� : " << CountCompleteLine(Bingo1) << endl;
			cout << "Bingo2�� ���� ���� : " << CountCompleteLine(Bingo2) << endl;
			break;
		}

	}

}

void FindNum(Bingo& bingo, int InputNum)
{
	for (int i = 0; i < bingo.GetBingoSize(); i++)
	{
		for (int j = 0; j < bingo.GetBingoSize(); j++)
		{
			if (InputNum == bingo.GetBingoSpace(i, j))
			{
				// ��ġ�� ���� ������ -1�� �ٲ������
				bingo.RenewBingoSpace(i, j);
				break;
			}
		}
	}
}

int CountCompleteLine(Bingo& bingo)
{
	int Result = 0;
	int temp = 0;

	// ���� ���η� Ȯ��
	for (int i = 0; i < bingo.GetBingoSize(); i++)
	{
		// temp�� -1�� ���� ������ 1�� ���� �����ϴµ� ���� ���� ũ�Ⱚ��ŭ Ŀ���� �� -1�̶�°Ŵϱ� Result++�Ѵ�
		for (int j = 0; j < bingo.GetBingoSize(); j++)
		{
			if (bingo.GetBingoSpace(i, j) == -1)
			{
				temp++;
			}
		}
		if (temp == bingo.GetBingoSize())
		{
			Result++;
			temp = 0;
		}
		else
		{
			temp = 0;
		}
	}

	// ���� ���η� Ȯ��
	for (int i = 0; i < bingo.GetBingoSize(); i++)
	{
		// temp�� -1�� ���� ������ 1�� ���� �����ϴµ� ���� ���� ũ�Ⱚ��ŭ Ŀ���� �� -1�̶�°Ŵϱ� Result++�Ѵ�
		for (int j = 0; j < bingo.GetBingoSize(); j++)
		{
			if (bingo.GetBingoSpace(j, i) == -1)
			{
				temp++;
			}
		}
		if (temp == bingo.GetBingoSize())
		{
			Result++;
			temp = 0;
		}
		else
		{
			temp = 0;
		}
	}

	// ���� �밢�� Ȯ��1
	for (int i = 0; i < bingo.GetBingoSize(); i++)
	{
		if (bingo.GetBingoSpace(i, i) == -1)
		{
			temp++;
		}
	}
	if (temp == bingo.GetBingoSize())
	{
		Result++;
		temp = 0;
	}
	else
	{
		temp = 0;
	}

	// ���� �밢�� Ȯ��2
	for (int i = 0; i < bingo.GetBingoSize(); i++)
	{
		if (bingo.GetBingoSpace(bingo.GetBingoSize() - i - 1, i) == -1)
		{
			temp++;
		}
	}
	if (temp == bingo.GetBingoSize())
	{
		Result++;
		temp = 0;
	}
	else
	{
		temp = 0;
	}

	return Result;
}

// �����ǿ��� ������ ���ڸ� -1 ��� X�� �����ֱ�
// Bingo1, Bingo2�� &�� �� ������ �����ؼ� �����ߴٰ� �Ҹ�ż� ���̴µ�???
void ShowX(Bingo &Bingo1, Bingo &Bingo2)
{
	cout << "[Bingo1]" << right << setw(Bingo1.GetBingoSize() * 5 + 15 - 8) << " " << "[Bingo2]" << endl;
	for (int i = 0; i < Bingo1.GetBingoSize(); i++)
	{
		for (int j = 0; j < Bingo1.GetBingoSize(); j++)
		{
			if (Bingo1.GetBingoSpace(i, j) == -1)
			{
				cout << right << setw(5) << 'X';
			}
			else
			{
				cout << right << setw(5) << Bingo1.GetBingoSpace(i, j);
			}
		}

		cout << right << setw(15) << " ";

		// �����ʿ� 2��° ������ ǥ��
		for (int j = 0; j < Bingo1.GetBingoSize(); j++)
		{
			if (Bingo2.GetBingoSpace(i, j) == -1)
			{
				cout << right << setw(5) << 'X';
			}
			else
			{
				cout << right << setw(5) << Bingo2.GetBingoSpace(i, j);
			}
		}

		cout << endl;
	}
}