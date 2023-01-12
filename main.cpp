#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "L20221229.h"
#include "L20221230.h"
#include "L20230105.h"
#include "Windows.h"
#include "L20230106.h"
//#include "L20230110.h"
#include "Player.h"
#include "Grid2D.h"
#include "Enemy.h"
#include "GameObject.h"

using namespace std;

// or, and������ ����ϱ� ����
inline CharacterStatusFlags operator|(CharacterStatusFlags a, CharacterStatusFlags b)
{
	return static_cast<CharacterStatusFlags>(static_cast<int>(a) | static_cast<int>(b));
}
inline CharacterStatusFlags operator&(CharacterStatusFlags a, CharacterStatusFlags b)
{
	return static_cast<CharacterStatusFlags>(static_cast<int>(a) & static_cast<int>(b));
}


// �ֿܼ��� Ŀ�� �� ���̰� �ϱ�
void ShowConsoleCursor(bool Show)
{
	auto Out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(Out, &CursorInfo);
	CursorInfo.bVisible = Show;
	SetConsoleCursorInfo(Out, &CursorInfo);
}

void Add(int A, int B){}

static int GlobalCnt = 0; // �̰Ŵ� ����ƽ ������ ����� �۷ι� ������ ���� ������ ��𼭵� ���� ����

int main()
{
	////Start();

	//char Text[] = { 'A','P','P','L','E' };
	//int ArraySize = sizeof(Text);
	//char Text2[10];

	//// �迭 ���. ����
	//Output(Text, ArraySize);

	//// ���� �ٲٱ� �Լ� ����
	//Reverse(Text, Text2, ArraySize);

	//// �迭 ���. �ٲ������ Ȯ��
	//Output(Text, ArraySize);

	//// �迭 ���. ������ �� ����Ǿ����� Ȯ��
	//Output(Text2, ArraySize);


	//cout << endl << endl << endl;


	//srand(time(NULL));

	//float Health, Damage, Armor;
	//int DodgeRate;
	//Health = 100;

	//cout << "**********���� ü���� 100�Դϴ�. ������� ���º��� ������ ü���� ���� �ʽ��ϴ�**********" << endl;
	//while (Health > 0)
	//{
	//	cout << "�����, ����, ȸ����(%, ����)�� �Է����ּ���." << endl;

	//	cin >> Damage >> Armor >> DodgeRate;

	//	TakeDamage(Health, Damage, Armor, DodgeRate);

	//	cout << "���ݴ��� �� ü���� [" << Health << "]�Դϴ�.\n" << endl;

	//	if (Health <= 0)
	//		cout << "�÷��̾� ĳ���Ͱ� �׾����ϴ�." << endl;
	//}


	//// �����͵��� ����Ű�� ����� �ٲٴ� ���α׷�
	//// ������ A�� A�� �ּҸ� ����Ű�ٰ� B�� �ּҷ�, ������ B�� B�� �ּҸ� ����Ű�ٰ� A�� �ּҷ�
	//int* PtrA;
	//int* PtrB;
	//int A = 10, B = 20;
	//PtrA = &A;
	//PtrB = &B;
	//cout << "���� ��" << endl;
	//cout << "A�� ���� : [" << A << "], PtrA �޸� �ּҴ� : [" << PtrA << "], PtrA�� ���۷��� ���� : [" << *PtrA << "]" << endl;
	//cout << "B�� ���� : [" << B << "], PtrB �޸� �ּҴ� : [" << PtrB << "], PtrB�� ���۷��� ���� : [" << *PtrB << "]" << endl << endl;

	//int* temp;
	//temp = PtrA;
	//PtrA = PtrB;
	//PtrB = temp;
	//cout << "���� ��" << endl;
	//cout << "A�� ���� : [" << A << "], PtrA �޸� �ּҴ� : [" << PtrA << "], PtrA�� ���۷��� ���� : [" << *PtrA << "]" << endl;
	//cout << "B�� ���� : [" << B << "], PtrB �޸� �ּҴ� : [" << PtrB << "], PtrB�� ���۷��� ���� : [" << *PtrB << "]" << endl << endl;

	//int* &PtrC = PtrA; // int* &PtrC = &A �̰� �� �ȴ�. ���۷����� Ư�� ������ ������Ÿ�Կ� ������ ���̴°Ŷ� ���� �ƴ� ������Ÿ���� ������ �;��Ѵ�.
	//cout << "int* &PtrC = PtrA" << endl;
	//cout << "PtrC : " << PtrC << ", &PtrC : " << &PtrC << ", *PtrC : " << *PtrC << endl << endl;

	//int** PtrD = &PtrA;
	//cout << "int** PtrD = &PtrA" << endl;
	//cout << "PtrD : " << PtrD << ", &PtrD : " << &PtrD << ", *PtrD : " << *PtrD << ", **PtrD : " << **PtrD << endl;


	//int Num1 = 11, Num2 = 22;
	//int* PtrA = &Num1;
	//int* PtrB = &Num2;
	//cout << "���� ��	" << "Num1 : [" << Num1 << "], Num2 : [" << Num2 << "]" << endl;
	//
	//Swap1(&Num1, &Num2);
	//cout << "Swap1	" << "Num1 : [" << Num1 << "], Num2 : [" << Num2 << "]" << endl;

	//Swap2(Num1, Num2);
	//cout << "Swap2	" << "Num1 : [" << Num1 << "], Num2 : [" << Num2 << "]" << endl << endl;


	////������
	//cout << "���� ��	" << "PtrA : [" << PtrA << "], PtrB : [" << PtrB << "]" << endl;

	//SwapPointer1(&PtrA, &PtrB);
	//cout << "Swap1	" << "PtrA : [" << PtrA << "], PtrB : [" << PtrB << "]" << endl;

	//SwapPointer2(PtrA, PtrB);
	//cout << "Swap2	" << "PtrA : [" << PtrA << "], PtrB : [" << PtrB << "]" << endl;


	//char Command = 'A';
	//do
	//{
	//	cout << "���丮���� ����� ������ �Է����ּ���." << endl;
	//	int InputNum = 0;
	//	cin >> InputNum;
	//	cout << InputNum << "!���� : " << FactorialLimited(InputNum) << endl;
	//	cout << "\n�����Ͻ÷��� q�� �Է��ϼ���." << endl;
	//	cin >> Command;
	//	cout << endl;
	//} while (Command != 'q');


	//Rect Quadrangle;
	//cout << "�簢���� ���� ���̸� �Է��ϼ���." << endl;
	//cin >> Quadrangle.Width;
	//cout << "�簢���� ���� ���̸� �Է��ϼ���." << endl;
	//cin >> Quadrangle.Height;

	//CalRect(Quadrangle);
	//cout << "�簢���� ���̴� : " << Quadrangle.Area << endl;
	//cout << "�簢���� �ѷ��� : " << Quadrangle.Circumference << endl;

	////Rect Rect = {10,5}; �̷������� �迭ó�� �ʱ�ȭ�� ����


	//// ����ü
	//Student StudentArray[10];
	//srand(time(NULL));
	//int Rand = 0;

	//for (int i = 0; i < 10; i++)
	//{
	//	Rand = rand() % 4 + 8; // 8~11 ������ ������ ��. �� ��ǥ�� �� ���� �ֵ��� �ߺ�ó���� �غ���.
	//	StudentArray[i].Name = 65 + i;
	//	StudentArray[i].Coordinate.X = Rand;
	//	StudentArray[i].Coordinate.Y = Rand;

	//	//PrintLocation(StudentArray[i]);
	//}

	//Student StudentA = Student("KSH", 33, 95, 80);
	//Student StudentB = Student("PSW", 30, 75, 90);
	//Student StudentC = Student("KJW", 28, 45, 50);
	//Student StudentArray2[] = { StudentA, StudentB, StudentC };

	//PrintLocation1(StudentArray, 10);


	// ���ʹ����
	//SushiGame();


	//// People ��ü�� ���� ����� Ŀ���� ������ �����ϰ� ��� ������ ����ϱ�
	//// People ��ü�� ��� ��������� ������ �����ϱ�
	//People *PeopleA = new People;
	//PeopleA->Name = "KoSihoon";
	//PeopleA->Age = 33;
	//PeopleA->PeopleCoord = new Coord;
	//PeopleA->PeopleCoord->SetCoord(5, 5);

	//People* PeopleB = new People;
	//PeopleB->Name = "Sonic";
	//PeopleB->Age = 35;
	//PeopleB->PeopleCoord = new Coord;
	//PeopleB->PeopleCoord->SetCoord(7, 3);

	//People* PeopleC = new People("Faker", 27, new Coord(10, 10)); //  �̰� �ǳ�?!

	//const int Size = 3;
	//People* PtrPeople[Size] = { PeopleA,PeopleB,PeopleC };

	//// ������ People* �����ϰ� �迭�� ���� �͵��� �Ʒ� �ڵ�� ����
	////for (int i = 0; i < Size; i++)
	////{
	////	PtrPeople[Size] = new People;
	////}

	//for (int i = 0; i < Size; i++)
	//{
	//	PtrPeople[i]->Move();
	//	PtrPeople[i]->Eat();
	//	PtrPeople[i]->Speak();
	//	cout << "\n";
	//}

	//// ������ �����
	//for (int i = 0; i < Size; i++)
	//{
	//	delete PtrPeople[i];
	//}


	//// ������ ������ Ÿ�ӿ� �������� ������ �޸𸮰��� �󸶳� ������ �˾ƾ��Ѵ�. ���� �ƴϾ ��
	//int ArraySize = 10;
	//int ExampleArray[5]; // �������� ���ÿ� �����ϸ鼭 �̷������� �ؾ߸� �ߴ�.
	//int* HArray = new int[ArraySize];

	//for (int i = 0; i < ArraySize; i++)
	//{
	//	*(HArray + i) = i + 1;
	//	cout << *(HArray + i) << " ";
	//}
	//cout << endl;
	//for (int i = 0; i < ArraySize; i++)
	//{
	//	cout << "*(HArray) : " << *HArray << endl;
	//	cout << "HArray : " << HArray++ << endl << endl;
	//	//Sleep(100);
	//}
	//cout << endl;
	//for (int i = 0; i < ArraySize; i++)
	//{
	//	cout << "*(HArray) : " << (--HArray)[0] << endl; // *(--HArray) == (--HArray)[0] != --HArray[0] ���� ��������!
	//	cout << "HArray : " << HArray << endl << endl;
	//	//Sleep(100);
	//}

	//int X = 5, Y = 5;
	//int** HArray2D = new int* [X];
	//for (int i = 0; i < X; i++)
	//{
	//	HArray2D[i] = new int[Y]; // i��°�� Yũ���� int�迭�� ����� �ּҸ� �� ��. new�� �ּҸ� ���� ����� �ּҸ� �ѱ�°Ŵ�.
	//}

	//// 2���� �迭 ���� �� �ʱ�ȭ
	//for (int i = 0; i < X; i++)
	//{
	//	for (int j = 0; j < Y; j++)
	//	{
	//		HArray2D[i][j] = i * Y + j + 1;
	//		cout << "HArray2D[" << i << "][" << j << "] : " << HArray2D[i][j] << "\n";
	//	}
	//}

	//// �迭�� ���� ������ ���Ŵ����� �˾Ƶ��� �� �ֵ��� delete [] �� ǥ������� �Ѵ�.
	//for (int i = 0; i < X; i++)
	//{
	//	delete[] HArray2D[i];
	//}
	//delete[] HArray2D;


	// �ں������
	//BingoGame();


	//CharacterStatusFlags Status = CharacterStatusFlags::None;
	//Status = Status | CharacterStatusFlags::Slow; // or�� and�� ���ǰ� �� �Ǿ��־ ������ ������
	//Status = Status & CharacterStatusFlags::Slow; // and�� �� ���°� �´��� ���ǹ����� Ȱ���Ѵ�
	//// �̻���¿��� ȸ���Ϸ��� 1�ΰ� 0���� �ϴ°Ŵϰ� not�ϰ� &Ȱ���ϸ� �ȴ�


/*	People PeopleA("Human", 100);
	PeopleA.Print();
	cout << endl;
	//Character Me("SuperGuild");
	//Me.Print();
	Character Me("Sihoon", 33, "HyperGuild"); // �θ� ������ �� �̸��̶� ���� �޴� ������ ����Ѱ�
	Me.Print();
	Me.cry();
	cout << endl;
	Enemy Slime;
	Slime.Print();
	Slime.cry();
	cout << endl;
	Enemy BossMonster("SuperBoss", 100, 1000, "�����");
	BossMonster.Print();
	BossMonster.cry();
	cout << endl;

	//Character* PtrChar = &PeopleA;
	//People* PtrPeo = &Me;
	//PtrPeo->cry();

	People TestPeople = Me;
	TestPeople.Print();

	//PtrPeo = new Character;


	int* PA = new int;
	int* PtrA[3] = { PA, };
	cout << *PtrA[0] << endl;
	cout << *PA << endl;

	cout << "ť ����� �Է����ּ���(1�̻�)." << endl;
	int Size, Num;
	cin >> Size;
	QueueOld GameQueue(Size);

	while (true)
	{
		for (int i = 0; i < GameQueue.GetFront(); i++)
		{
			GameQueue.ShowArray(GameQueue.GetFront() - i - 1);
		}

		while (true)
		{
			cout << "\nEnqueue : 1�̻��� ���� �Է�" << endl;
			cout << "Dequeue : 0 �Է�" << endl;

			cin >> Num;
			if (Num < 0)
			{
				cout << "�ٽ� �Է����ּ���." << endl;
				continue;
			}

			break;
		}

		// ȭ�� ����ϰ��ϱ�
		system("cls");

		// 0�̸� ��ť. 1�̻��̸� ��ť
		if (Num == 0)
		{
			GameQueue.Dequeue();
			continue;
		}
		GameQueue.Enqueue(Num);
	}



	// ť ������� ����
	cout << "ť ����� �Է����ּ���(1�̻�)." << endl;
	int Size, Num;
	cin >> Size;
	Queue NewGameQueue(Size);

	while (true)
	{
		// ȭ�鿡 ���� �����ֱ�
		NewGameQueue.ShowArray();

		while (true)
		{
			cout << "\nEnqueue : 1�̻��� ���� �Է�" << endl;
			cout << "Dequeue : 0 �Է�" << endl;

			cin >> Num;
			if (Num < 0)
			{
				cout << "�ٽ� �Է����ּ���." << endl;
				continue;
			}
			break;
		}

		// ȭ�� ����ϰ��ϱ�
		system("cls");

		// 0�̸� ��ť. 1�̻��̸� ��ť
		if (Num == 0)
		{
			NewGameQueue.Dequeue();
			continue;
		}
		NewGameQueue.Enqueue(Num);
	}
	*/


	/*
		// �θ� �����Ϳ� �ڽ� ��ü �ּ�or �ڽ� ������ �־��.
		People NPC1 = People("����", 50);
		Character Warrior = Character("����", 35, "�ѹټ���");
		People* PeoplePointer = &NPC1;
		Character* CharacterPointer = &Warrior;

		//PeoplePointer = CharacterPointer;
		//PeoplePointer->People::cry();
		//PeoplePointer->Print();

		// ����ȯ.
		((Character*)PeoplePointer)->GetStatus(); // �ٵ� �̰� �ƹ� �͵� �� ���´�. PeoplePointer�� Character ��ü�� ����Ű�� ���� �ʾƼ�
		CharacterPointer = dynamic_cast<Character*>(PeoplePointer); // ����� ĳ������ �� �Ǹ� nullptr�� ����. PeoplePointer�� Character��ü�� ����Ű�� �־����� �����, �ƴϸ� nullptr
		if (CharacterPointer != nullptr)
		{
			CharacterPointer->GetGuild();
		}




		// �ڿ��ÿ� ���ӡ�
		int PlayerX = 1, PlayerY = 1; // �÷��̾� ��ǥ
		string Id = "A"; // �÷��̾� ǥ��

		int SizeX = 20, SizeY = 20;
		cout << "���� ũ�⸦ �Է����ּ���(X -> Y ������ 2�� �Է�)" << endl;
		cin >> SizeX >> SizeY;

		char** Map = new char* [SizeX];
		for (int i = 0; i < SizeX; i++)
		{
			Map[i] = new char[SizeY];
		}

		// �ʱ�ȭ
		for (int i = 0; i < SizeX; i++)
		{
			for (int j = 0; j < SizeY; j++)
			{
				// �׵θ� �κ�. x�� 0or9�� ���� y�� 0or9�� ��
				if (i == 0 || i == SizeX - 1 || j == 0 || j == SizeY - 1) // �̰� ���� �� �ߴ�. ���� ���ĵ� �ǳ�
				{
					Map[i][j] = '#';
				}
				// �Ϲ����� ���
				else
				{
					Map[i][j] = ' ';
				}
			}
		}

		PlayerX = 2, PlayerY = 2;
		Map[PlayerX][PlayerY] = 'A';

		// ���. ���� ��������!
		for (int i = 0; i < SizeY; i++)
		{
			for (int j = 0; j < SizeX; j++)
			{
				cout << Map[j][i] << " ";
			}
			cout << endl;
		}

		cout << endl << endl;

		// (0,0)�� �����ϴ����� ������ ����ϱ�. Y�� �������� ��½��״�
		cout << "---�ͼ��� ��ǥ��ó�� ���---" << endl;
		for (int i = 0; i < SizeY; i++)
		{
			for (int j = 0; j < SizeX; j++)
			{
				cout << Map[j][SizeY - i - 1] << " ";
			}
			cout << endl;
		}


		for (int i = 0; i < SizeX; i++)
		{
			delete[] Map[i];
		}
		delete[] Map;
	



	// Ŭ������ �ٲ㼭 ���ÿ� ���� �غ���
	cout << "����� X, Y ������ �Է����ּ���." << endl;
	int X, Y;
	cin >> X >> Y;

	Grid2D Grid(X, Y);
	Player MyPlayer("O", 2, 2);
	//MyPlayer.SetBound(Grid.GetSizeX(), Grid.GetSizeY()); // �� ũ�� �÷��̾� Ŭ���� ��ü�� �ѱ��
	//Grid.SetPlayer(&MyPlayer); // �ּҸ� �� �ѱ�� ���� �����ϴ� �ٶ��� ���ο��� move�ص� ����� Player�� �״�ζ� ȭ�鿡�� �������� �ʴ´�
	Grid.Update();
	Grid.Draw();

	cout << endl;
	//MyPlayer.Move(Direction::Right);


	// ���콺 Ŀ�� �� ���̰� �ϱ�
	ShowConsoleCursor(false);
	
	Enemy Monster = Enemy("Monster", 5, 5);
	//Monster.SetBound(Grid.GetSizeX(), Grid.GetSizeY());
	//Grid.AddEnemy(&Monster); // Enemy �߰��ϴ� �Լ��� �ʿ��������� ���������. �ּ� �ѱ�°� ���� ����

	Grid.AddGameObject(&MyPlayer);
	Grid.AddGameObject(&Monster);




	srand((unsigned int)time(NULL));
	int MonsterRandom = -1;

	while (true)
	{
		if (GetKeyState('W') & 0x8000) // � Ű�� ���ȴ��� �˷��ִ°� GetKeyState. ��ҹ��� �� ������. 0x8000�� ����? windows.h �ʿ��ϴ�
		{
			MyPlayer.Move(Direction::Up);
		}
		else if (GetKeyState('S') & 0x8000)
		{
			MyPlayer.Move(Direction::Down);
		}
		else if (GetKeyState('D') & 0x8000)
		{
			MyPlayer.Move(Direction::Right);
		}
		else if (GetKeyState('A') & 0x8000)
		{
			MyPlayer.Move(Direction::Left);
		}
		else if (GetKeyState('C') & 0x8000)
		{
			Grid.CreateGameObject();
		}
		// ����!
		else if (GetKeyState(VK_SPACE) & 0x8000)
		{
			MyPlayer.Attack(); // �����Լ��� �ʿ��������� ������ �Ѵ�
		}

		// Monster �������� �����̱�
		for (int i = 1; i < Grid.GetCurrentGameObject(); i++)
		{
			MonsterRandom = (unsigned int)rand() % 4;
			if (MonsterRandom == 0)
			{
				Grid.NewMap[i]->Move(Direction::Up);
			}
			else if (MonsterRandom == 1)
			{
				Grid.NewMap[i]->Move(Direction::Down);
			}
			else if (MonsterRandom == 2)
			{
				Grid.NewMap[i]->Move(Direction::Right);
			}
			else if (MonsterRandom == 3)
			{
				Grid.NewMap[i]->Move(Direction::Left);
			}
		}

		

		//Grid.Update();
		//Grid.Draw();
	}
	*/



	void (*FuncPtr)(int, int);
	FuncPtr = &Add;






	return 0;
}



// ����ȯ Ȱ�� ��
//asdf(Animal* Animal)
//{
//	Dog* Dog;
//	Dog = Animal; // ���⼭ ���̳��� ĳ������ �Ͼ
//	if (Dog != nullptr)
//	{
//		asdfsad
//	}
//}