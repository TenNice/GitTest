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

// or, and연산자 사용하기 위해
inline CharacterStatusFlags operator|(CharacterStatusFlags a, CharacterStatusFlags b)
{
	return static_cast<CharacterStatusFlags>(static_cast<int>(a) | static_cast<int>(b));
}
inline CharacterStatusFlags operator&(CharacterStatusFlags a, CharacterStatusFlags b)
{
	return static_cast<CharacterStatusFlags>(static_cast<int>(a) & static_cast<int>(b));
}


// 콘솔에서 커서 안 보이게 하기
void ShowConsoleCursor(bool Show)
{
	auto Out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(Out, &CursorInfo);
	CursorInfo.bVisible = Show;
	SetConsoleCursorInfo(Out, &CursorInfo);
}

void Add(int A, int B){}

static int GlobalCnt = 0; // 이거는 스태틱 영역에 생기는 글로벌 변수라 파일 내에서 어디서든 접근 가능

int main()
{
	////Start();

	//char Text[] = { 'A','P','P','L','E' };
	//int ArraySize = sizeof(Text);
	//char Text2[10];

	//// 배열 출력. 원본
	//Output(Text, ArraySize);

	//// 순서 바꾸기 함수 실행
	//Reverse(Text, Text2, ArraySize);

	//// 배열 출력. 바뀌었는지 확인
	//Output(Text, ArraySize);

	//// 배열 출력. 원본이 잘 복사되었는지 확인
	//Output(Text2, ArraySize);


	//cout << endl << endl << endl;


	//srand(time(NULL));

	//float Health, Damage, Armor;
	//int DodgeRate;
	//Health = 100;

	//cout << "**********시작 체력은 100입니다. 대미지가 방어력보다 낮으면 체력이 닳지 않습니다**********" << endl;
	//while (Health > 0)
	//{
	//	cout << "대미지, 방어력, 회피율(%, 정수)을 입력해주세요." << endl;

	//	cin >> Damage >> Armor >> DodgeRate;

	//	TakeDamage(Health, Damage, Armor, DodgeRate);

	//	cout << "공격당한 후 체력은 [" << Health << "]입니다.\n" << endl;

	//	if (Health <= 0)
	//		cout << "플레이어 캐릭터가 죽었습니다." << endl;
	//}


	//// 포인터들이 가리키는 대상을 바꾸는 프로그램
	//// 포인터 A는 A의 주소를 가리키다가 B의 주소로, 포인터 B는 B의 주소를 가리키다가 A의 주소로
	//int* PtrA;
	//int* PtrB;
	//int A = 10, B = 20;
	//PtrA = &A;
	//PtrB = &B;
	//cout << "변경 전" << endl;
	//cout << "A의 값은 : [" << A << "], PtrA 메모리 주소는 : [" << PtrA << "], PtrA의 디레퍼런싱 값은 : [" << *PtrA << "]" << endl;
	//cout << "B의 값은 : [" << B << "], PtrB 메모리 주소는 : [" << PtrB << "], PtrB의 디레퍼런싱 값은 : [" << *PtrB << "]" << endl << endl;

	//int* temp;
	//temp = PtrA;
	//PtrA = PtrB;
	//PtrB = temp;
	//cout << "변경 후" << endl;
	//cout << "A의 값은 : [" << A << "], PtrA 메모리 주소는 : [" << PtrA << "], PtrA의 디레퍼런싱 값은 : [" << *PtrA << "]" << endl;
	//cout << "B의 값은 : [" << B << "], PtrB 메모리 주소는 : [" << PtrB << "], PtrB의 디레퍼런싱 값은 : [" << *PtrB << "]" << endl << endl;

	//int* &PtrC = PtrA; // int* &PtrC = &A 이건 안 된다. 레퍼런스는 특정 형태의 데이터타입에 별명을 붙이는거라 값이 아닌 데이터타입의 변수가 와야한다.
	//cout << "int* &PtrC = PtrA" << endl;
	//cout << "PtrC : " << PtrC << ", &PtrC : " << &PtrC << ", *PtrC : " << *PtrC << endl << endl;

	//int** PtrD = &PtrA;
	//cout << "int** PtrD = &PtrA" << endl;
	//cout << "PtrD : " << PtrD << ", &PtrD : " << &PtrD << ", *PtrD : " << *PtrD << ", **PtrD : " << **PtrD << endl;


	//int Num1 = 11, Num2 = 22;
	//int* PtrA = &Num1;
	//int* PtrB = &Num2;
	//cout << "변경 전	" << "Num1 : [" << Num1 << "], Num2 : [" << Num2 << "]" << endl;
	//
	//Swap1(&Num1, &Num2);
	//cout << "Swap1	" << "Num1 : [" << Num1 << "], Num2 : [" << Num2 << "]" << endl;

	//Swap2(Num1, Num2);
	//cout << "Swap2	" << "Num1 : [" << Num1 << "], Num2 : [" << Num2 << "]" << endl << endl;


	////포인터
	//cout << "변경 전	" << "PtrA : [" << PtrA << "], PtrB : [" << PtrB << "]" << endl;

	//SwapPointer1(&PtrA, &PtrB);
	//cout << "Swap1	" << "PtrA : [" << PtrA << "], PtrB : [" << PtrB << "]" << endl;

	//SwapPointer2(PtrA, PtrB);
	//cout << "Swap2	" << "PtrA : [" << PtrA << "], PtrB : [" << PtrB << "]" << endl;


	//char Command = 'A';
	//do
	//{
	//	cout << "팩토리얼을 계산할 정수를 입력해주세요." << endl;
	//	int InputNum = 0;
	//	cin >> InputNum;
	//	cout << InputNum << "!값은 : " << FactorialLimited(InputNum) << endl;
	//	cout << "\n종료하시려면 q를 입력하세요." << endl;
	//	cin >> Command;
	//	cout << endl;
	//} while (Command != 'q');


	//Rect Quadrangle;
	//cout << "사각형의 가로 길이를 입력하세요." << endl;
	//cin >> Quadrangle.Width;
	//cout << "사각형의 세로 길이를 입력하세요." << endl;
	//cin >> Quadrangle.Height;

	//CalRect(Quadrangle);
	//cout << "사각형의 넓이는 : " << Quadrangle.Area << endl;
	//cout << "사각형의 둘레는 : " << Quadrangle.Circumference << endl;

	////Rect Rect = {10,5}; 이런식으로 배열처럼 초기화도 가능


	//// 구조체
	//Student StudentArray[10];
	//srand(time(NULL));
	//int Rand = 0;

	//for (int i = 0; i < 10; i++)
	//{
	//	Rand = rand() % 4 + 8; // 8~11 범위의 랜덤한 수. 한 좌표에 한 명씩만 있도록 중복처리도 해보자.
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


	// ★초밥게임
	//SushiGame();


	//// People 객체를 힙에 만들고 커스텀 데이터 저장하고 사람 정보들 출력하기
	//// People 객체를 모두 사용했으면 힙에서 삭제하기
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

	//People* PeopleC = new People("Faker", 27, new Coord(10, 10)); //  이게 되네?!

	//const int Size = 3;
	//People* PtrPeople[Size] = { PeopleA,PeopleB,PeopleC };

	//// ★위에 People* 생성하고 배열에 넣은 것들은 아래 코드와 같다
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

	//// 힙에서 지우기
	//for (int i = 0; i < Size; i++)
	//{
	//	delete PtrPeople[i];
	//}


	//// 스택은 컴파일 타임에 변수들이 무조건 메모리공간 얼마나 쓰는지 알아야한다. 힙은 아니어도 됨
	//int ArraySize = 10;
	//int ExampleArray[5]; // 기존에는 스택에 선언하면서 이런식으로 해야만 했다.
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
	//	cout << "*(HArray) : " << (--HArray)[0] << endl; // *(--HArray) == (--HArray)[0] != --HArray[0] 순서 주의하자!
	//	cout << "HArray : " << HArray << endl << endl;
	//	//Sleep(100);
	//}

	//int X = 5, Y = 5;
	//int** HArray2D = new int* [X];
	//for (int i = 0; i < X; i++)
	//{
	//	HArray2D[i] = new int[Y]; // i번째에 Y크기의 int배열을 만들고 주소를 준 것. new는 주소를 힙에 만들고 주소를 넘기는거다.
	//}

	//// 2차원 배열 만든 후 초기화
	//for (int i = 0; i < X; i++)
	//{
	//	for (int j = 0; j < Y; j++)
	//	{
	//		HArray2D[i][j] = i * Y + j + 1;
	//		cout << "HArray2D[" << i << "][" << j << "] : " << HArray2D[i][j] << "\n";
	//	}
	//}

	//// 배열을 지울 때에는 힙매니저가 알아들을 수 있도록 delete [] 로 표시해줘야 한다.
	//for (int i = 0; i < X; i++)
	//{
	//	delete[] HArray2D[i];
	//}
	//delete[] HArray2D;


	// ★빙고게임
	//BingoGame();


	//CharacterStatusFlags Status = CharacterStatusFlags::None;
	//Status = Status | CharacterStatusFlags::Slow; // or랑 and가 정의가 안 되어있어서 위에서 정의함
	//Status = Status & CharacterStatusFlags::Slow; // and는 그 상태가 맞는지 조건문에서 활용한다
	//// 이상상태에서 회복하려면 1인걸 0으로 하는거니가 not하고 &활용하면 된다


/*	People PeopleA("Human", 100);
	PeopleA.Print();
	cout << endl;
	//Character Me("SuperGuild");
	//Me.Print();
	Character Me("Sihoon", 33, "HyperGuild"); // 부모 생성자 중 이름이랑 나이 받는 생성자 사용한거
	Me.Print();
	Me.cry();
	cout << endl;
	Enemy Slime;
	Slime.Print();
	Slime.cry();
	cout << endl;
	Enemy BossMonster("SuperBoss", 100, 1000, "집행검");
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

	cout << "큐 사이즈를 입력해주세요(1이상)." << endl;
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
			cout << "\nEnqueue : 1이상의 숫자 입력" << endl;
			cout << "Dequeue : 0 입력" << endl;

			cin >> Num;
			if (Num < 0)
			{
				cout << "다시 입력해주세요." << endl;
				continue;
			}

			break;
		}

		// 화면 깔끔하게하기
		system("cls");

		// 0이면 디큐. 1이상이면 엔큐
		if (Num == 0)
		{
			GameQueue.Dequeue();
			continue;
		}
		GameQueue.Enqueue(Num);
	}



	// 큐 성능향상 버전
	cout << "큐 사이즈를 입력해주세요(1이상)." << endl;
	int Size, Num;
	cin >> Size;
	Queue NewGameQueue(Size);

	while (true)
	{
		// 화면에 스택 보여주기
		NewGameQueue.ShowArray();

		while (true)
		{
			cout << "\nEnqueue : 1이상의 숫자 입력" << endl;
			cout << "Dequeue : 0 입력" << endl;

			cin >> Num;
			if (Num < 0)
			{
				cout << "다시 입력해주세요." << endl;
				continue;
			}
			break;
		}

		// 화면 깔끔하게하기
		system("cls");

		// 0이면 디큐. 1이상이면 엔큐
		if (Num == 0)
		{
			NewGameQueue.Dequeue();
			continue;
		}
		NewGameQueue.Enqueue(Num);
	}
	*/


	/*
		// 부모 포인터에 자식 객체 주소or 자식 포인터 넣어보기.
		People NPC1 = People("상인", 50);
		Character Warrior = Character("전사", 35, "겉바속촉");
		People* PeoplePointer = &NPC1;
		Character* CharacterPointer = &Warrior;

		//PeoplePointer = CharacterPointer;
		//PeoplePointer->People::cry();
		//PeoplePointer->Print();

		// 형변환.
		((Character*)PeoplePointer)->GetStatus(); // 근데 이거 아무 것도 안 나온다. PeoplePointer가 Character 객체를 가리키고 있지 않아서
		CharacterPointer = dynamic_cast<Character*>(PeoplePointer); // 제대로 캐스팅이 안 되면 nullptr이 들어간다. PeoplePointer가 Character객체를 가리키고 있었으면 제대로, 아니면 nullptr
		if (CharacterPointer != nullptr)
		{
			CharacterPointer->GetGuild();
		}




		// ★예시용 게임★
		int PlayerX = 1, PlayerY = 1; // 플레이어 좌표
		string Id = "A"; // 플레이어 표시

		int SizeX = 20, SizeY = 20;
		cout << "맵의 크기를 입력해주세요(X -> Y 순서로 2번 입력)" << endl;
		cin >> SizeX >> SizeY;

		char** Map = new char* [SizeX];
		for (int i = 0; i < SizeX; i++)
		{
			Map[i] = new char[SizeY];
		}

		// 초기화
		for (int i = 0; i < SizeX; i++)
		{
			for (int j = 0; j < SizeY; j++)
			{
				// 테두리 부분. x가 0or9일 때랑 y가 0or9일 때
				if (i == 0 || i == SizeX - 1 || j == 0 || j == SizeY - 1) // 이건 생각 못 했다. 조건 합쳐도 되네
				{
					Map[i][j] = '#';
				}
				// 일반적인 경우
				else
				{
					Map[i][j] = ' ';
				}
			}
		}

		PlayerX = 2, PlayerY = 2;
		Map[PlayerX][PlayerY] = 'A';

		// 출력. 순서 주의하자!
		for (int i = 0; i < SizeY; i++)
		{
			for (int j = 0; j < SizeX; j++)
			{
				cout << Map[j][i] << " ";
			}
			cout << endl;
		}

		cout << endl << endl;

		// (0,0)을 왼쪽하단으로 내려서 출력하기. Y만 역순으로 출력시켰다
		cout << "---익숙한 좌표계처럼 출력---" << endl;
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
	



	// 클래스로 바꿔서 예시용 게임 해보기
	cout << "사이즈를 X, Y 순서로 입력해주세요." << endl;
	int X, Y;
	cin >> X >> Y;

	Grid2D Grid(X, Y);
	Player MyPlayer("O", 2, 2);
	//MyPlayer.SetBound(Grid.GetSizeX(), Grid.GetSizeY()); // 맵 크기 플레이어 클래스 객체에 넘기기
	//Grid.SetPlayer(&MyPlayer); // 주소를 안 넘기면 값을 복사하는 바람에 메인에서 move해도 복사된 Player는 그대로라 화면에서 움직이질 않는다
	Grid.Update();
	Grid.Draw();

	cout << endl;
	//MyPlayer.Move(Direction::Right);


	// 마우스 커서 안 보이게 하기
	ShowConsoleCursor(false);
	
	Enemy Monster = Enemy("Monster", 5, 5);
	//Monster.SetBound(Grid.GetSizeX(), Grid.GetSizeY());
	//Grid.AddEnemy(&Monster); // Enemy 추가하는 함수가 필요해졌으니 만들어주자. 주소 넘기는거 잊지 말고

	Grid.AddGameObject(&MyPlayer);
	Grid.AddGameObject(&Monster);




	srand((unsigned int)time(NULL));
	int MonsterRandom = -1;

	while (true)
	{
		if (GetKeyState('W') & 0x8000) // 어떤 키가 눌렸는지 알려주는게 GetKeyState. 대소문자 안 가리네. 0x8000은 엔드? windows.h 필요하다
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
		// 공격!
		else if (GetKeyState(VK_SPACE) & 0x8000)
		{
			MyPlayer.Attack(); // 공격함수가 필요해졌으니 만들어야 한다
		}

		// Monster 랜덤으로 움직이기
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



// 형변환 활용 예
//asdf(Animal* Animal)
//{
//	Dog* Dog;
//	Dog = Animal; // 여기서 다이나믹 캐스팅이 일어남
//	if (Dog != nullptr)
//	{
//		asdfsad
//	}
//}