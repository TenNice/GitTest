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

enum class CharacterStatusFlags // Flag가 붙으면 비트로 표현한다는 것. 이거의 경우는 하나의 비트가 하나의 캐릭터 상태를 나타낸다.
{
	None,
	Stun = 1 << 1, // 1을 왼쪽으로 쉬프트 1번
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
	string Name; // 헤더를 메인에 삽입 안 하면 string 못 쓰네. 왜?
	int Age;
	Coord* PeopleCoord; // 메모리 공간 덜 쓰려고?!
	People* Friends[100]; // People* 타입 변수 100개를 만드는 것. People주소를 100개 저장할 수 있게 된거다. 아래랑 같은 건데 사이즈를 미리 정해놔야한다는게 차이
	People** AnotherFriends; // 힙에 People* 타입 배열을 만들고 주소를 넘겨줄 변수다
	int FCount = 0;
	int Money = 0;

public:
	// 순수 가상 함수. 이게 있으면 추상화된거라 객체 생성이 불가능하다
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
		PeopleCoord = new Coord(); // PeopleCoord라는 애를 안 만들고 멤버함수를 사용하려고 했더니 제대로 동작 안 했다. 없는 애의 함수를 사용해서 그런가보다.
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
		// 널포인터인지 확인 후 삭제
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
		cout << Name << "님이 이동하였습니다." << endl;
	}
	void Speak()
	{
		cout << Name << " : 말하는 중!" << endl;
	}
	void Eat()
	{
		cout << Name << "님이 식사중입니다." << endl;
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

	// ★단순히 수만 증가시키면 어떤 친구가 추가되었는지 알 수도 없고 추가시키는 함수가 또 필요해진다.
	// 근데 People* 타입을 받아 People* 타입 배열인 AnotherFriends에 넣어주면 
	void AddFriend(People* Friend)
	{
		if (AnotherFriends[FCount] != nullptr)
		{
			AnotherFriends[FCount++] = Friend; // FCount는 비어있는 인덱스의 번호를 가리키게 되는 셈이다
		}
	}
	void RemoveFriend(People* Friend)
	{
		bool bCheck = false; // 입력받은 친구가 친구리스트에 존재하는지 확인 후 저장하려는 변수
		 
		// 친구가 0명이면 remove할 필요가 없다
		if (FCount > 0)
		{
			int temp = -1; // 삭제할 친구 인덱스 저장용
			for (int i = 0; i < FCount; i++)
			{
				if (AnotherFriends[i]->Name == Friend->Name) // 이름이 겹치지 않는다고 가정(ID처럼)
				{
					temp = i;
					delete Friend;

					// 친구 리스트에 입력한 친구가 있으면 true로
					bCheck = true;

					break;
				}
			}

			// for문 다 돌았으니까 다 체크한거고, 친구 리스트에 친구가 존재하지 않으면 return
			if (bCheck != true)
			{
				cout << "입력한 친구가 리스트에 존재하지 않습니다." << endl;
				return;
			}

			// 제가한 인덱스부터 뒤에 친구 앞으로 1칸씩 당기기
			for (int i = temp; i < FCount - 1; i++)
			{
				AnotherFriends[i] = AnotherFriends[i + 1];
			}

			// FCount 1 줄이기
			--FCount;
		}
		else
		{
			cout << "친구가 0명입니다." << endl;
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
	// 부모가 가진 순수가상함수 오버라이드
	virtual void cry() override
	{
		cout << "함성!" << endl;
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
	// 부모 생성자 중 원하는거 호출
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
	// 부모가 가진 순수가상함수 오버라이드
	virtual void cry() override
	{
		cout << "우우" << endl;
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



// 빙고 만들기
// 빙고 클래스를 만들 것
// 빙고판의 크기는 n*n이고 n은 입력받는다.
// 몇 개의 빙고를 완성해야 승리하는지도 숫자를 입력받는다. (최대 2n+2개겠네)

// ★★★★★하면서 든 생각★★★★★
// 클래스에 멤버변수로 선언했던게 나중가니 굳이 필요했을까 싶은게 있다. 승리조건(몇 줄). 얘가 이거까지 가지고 있어야 하나?
// 클래스가 기능을 어디까지 가지고 있어야 하나 설계하기가 쉽지 않다. 클래스 밖으로 뺀 함수 중에서도 얘를 클래스에 넣을걸 그랬나 싶은 것도 있고.
// ★클래스 밖으로 뺀 함수는 로직에 클래스 내부 멤버함수나 멤버변수를 쓰게하는게 좋지 않은 것 같다. 유연성이 떨어지지 않게 파라미터로 받게 하는게 차라리 나을듯!

// Input
// Tick(). 입력 처리랑 로직
// Rendering

// 숫자 빙고판을 만드니까 enum을 활용 못하네
class Bingo
{
private:
	int BingoSize = 0;
	int WinLineNum = 0;
	int** BingoSpace;
	int* Check; // 입력받은 값이 중복인지 확인하기 위한 체크용 배열

public:
	Bingo()
	{
		//int temp = 0;
		//cout << "몇 줄짜리 빙고판을 만들 것인지 입력해주세요." << endl;
		//cin >> temp;
		//SetBingoSize(temp);
		//cout << "빙고가 몇 줄 완성되어야 승리할지 입력해주세요." << endl;
		//cin >> temp;
		//SetWinLineNum(temp);
		//CreateBingoSpace();
		//cout << "빙고판이 생성되었습니다." << endl;
	}
	Bingo(int Size, int WinNum)
	{
		SetBingoSize(Size);
		SetWinLineNum(WinNum);
		CreateBingoSpace();
		CreateCheck(Size);
		cout << "빙고판이 생성되었습니다." << endl;
	}
	~Bingo()
	{
		delete BingoSpace;
		delete Check;
		cout << "빙고판이 소멸되었습니다." << endl;
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

	// BingoSize * BingoSize 크기의 빙고판 힙에 생성
	void CreateBingoSpace()
	{
		BingoSpace = new int* [BingoSize];
		for (int i = 0; i < BingoSize; i++)
		{
			BingoSpace[i] = new int[BingoSize];
		}
	}

	// 만들어진 빙고판에 숫자 입력받기
	void SetBingoSpace()
	{
		// 개선하고 싶은점
		// O(N^3)을 O(N^2)로 줄이기
		// 입력한 값을 BingoSpace에 넣는건 2차원 배열에 넣는거라 O^2

		bool bCheck; // 중복체크용

		cout << "빙고판에 숫자를 입력해주세요(숫자는 1 이상이어야 합니다)." << endl;
		for (int i = 0; i < BingoSize; i++)
		{
			for (int j = 0; j < BingoSize; j++)
			{
				cout << i * BingoSize + j + 1 << "번째 숫자 입력" << endl;
				cin >> BingoSpace[i][j];
				Check[i * BingoSize + j] = BingoSpace[i][j];

				bCheck = false;
				while (!bCheck)
				{
					// 중복인지 체크. for문이 몇 개야. 퍼포먼스 O(N^3).
					for (int k = 0; k < i * BingoSize + j; k++)
					{
						if (Check[k] == BingoSpace[i][j])
						{
							cout << "중복된 숫자입니다. 다시 입력해주세요." << endl;
							cin >> BingoSpace[i][j];
							Check[i * BingoSize + j] = BingoSpace[i][j];
							k = -1; // 이거 다시 for반복문으로 가면 초기화 부분이 무시되고 바로 k++ 되는건가?? 0넣으니까 Check[0]은 체크를 안 하네
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
		// 0으로 초기화
		for (int i = 0; i < size * size; i++)
		{
			Check[i] = 0;
		}
	}

};

// 입력한 숫자 있나 찾는 함수 선언만
void FindNum(Bingo& bingo, int InputNum);

// 빙고 몇 개 완성됐는지 확인하는 함수 선언만
int CountCompleteLine(Bingo& bingo);

// 지운 숫자 X로 보여주기 함수 선언만
void ShowX(Bingo& Bingo1, Bingo& Bingo2);

void BingoGame()
{
	int InputBingoSize = 0, InputWinLineNum = 0;
	cout << "몇 줄짜리 빙고판을 만들 것인지 입력해주세요." << endl;
	cin >> InputBingoSize;
	cout << "빙고가 몇 줄 완성되어야 승리할지 입력해주세요." << endl;
	cin >> InputWinLineNum;

	Bingo Bingo1 = Bingo(InputBingoSize, InputWinLineNum);
	Bingo Bingo2 = Bingo(InputBingoSize, InputWinLineNum);

	Bingo1.SetBingoSpace();
	Bingo2.SetBingoSpace();

	cout << endl;

	// Tick()
	while (true)
	{
		// 화면 깔끔하게하기
		system("cls");

		cout << "승리할 수 있는 빙고 개수(Goal) : " << InputWinLineNum << endl;
		cout << "Bingo1의 이전 빙고 개수 : " << CountCompleteLine(Bingo1) << endl;
		cout << "Bingo2의 이전 빙고 개수 : " << CountCompleteLine(Bingo2) << endl << endl;


		ShowX(Bingo1, Bingo2);


		int temp = 0;
		cout << "\n제거할 숫자를 입력해주세요." << endl;
		cin >> temp;

		// 빙고판의 숫자 중 같은 숫자가 있다면 -1로
		FindNum(Bingo1, temp);
		FindNum(Bingo2, temp);


		// 각 빙고의 승리 조건 충족 여부 확인 후 승리 시 결과 출력
		if ((CountCompleteLine(Bingo1) >= Bingo1.GetWinLineNum()) && (CountCompleteLine(Bingo2) < Bingo2.GetWinLineNum()))
		{
			cout << "Bingo1의 승리입니다!" << endl;
			cout << "Bingo1의 빙고 개수 : " << CountCompleteLine(Bingo1) << endl;
			cout << "Bingo2의 빙고 개수 : " << CountCompleteLine(Bingo2) << endl;
			break;
		}
		else if ((CountCompleteLine(Bingo2) >= Bingo2.GetWinLineNum()) && (CountCompleteLine(Bingo1) < Bingo1.GetWinLineNum()))
		{
			cout << "Bingo2의 승리입니다!" << endl;
			cout << "Bingo1의 빙고 개수 : " << CountCompleteLine(Bingo1) << endl;
			cout << "Bingo2의 빙고 개수 : " << CountCompleteLine(Bingo2) << endl;
			break;
		}
		else if ((CountCompleteLine(Bingo2) >= Bingo2.GetWinLineNum()) && (CountCompleteLine(Bingo1) >= Bingo1.GetWinLineNum()))
		{
			cout << "무승부입니다." << endl;
			cout << "Bingo1의 빙고 개수 : " << CountCompleteLine(Bingo1) << endl;
			cout << "Bingo2의 빙고 개수 : " << CountCompleteLine(Bingo2) << endl;
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
				// 겹치는 숫자 있으면 -1로 바꿔버리기
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

	// 빙고 가로로 확인
	for (int i = 0; i < bingo.GetBingoSize(); i++)
	{
		// temp가 -1을 만날 때마다 1씩 값이 증가하는데 빙고 가로 크기값만큼 커지면 다 -1이라는거니까 Result++한다
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

	// 빙고 세로로 확인
	for (int i = 0; i < bingo.GetBingoSize(); i++)
	{
		// temp가 -1을 만날 때마다 1씩 값이 증가하는데 빙고 가로 크기값만큼 커지면 다 -1이라는거니까 Result++한다
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

	// 빙고 대각선 확인1
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

	// 빙고 대각선 확인2
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

// 빙고판에서 지워진 숫자를 -1 대신 X로 보여주기
// Bingo1, Bingo2를 &로 안 받으면 복사해서 생성했다가 소멸돼서 꼬이는데???
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

		// 오른쪽에 2번째 빙고판 표시
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