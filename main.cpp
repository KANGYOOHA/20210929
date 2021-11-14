#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

void Input();
void Process();
void Draw();
void MovePlayer(int XDirection,int YDirection);

void ChangeColor(int Color);

int Map[10][10] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,0,1,0,1},
	{1,0,0,0,1,0,0,1,0,1},
	{1,0,0,0,1,0,0,1,9,1},
	{1,1,1,1,1,1,1,1,1,1}
};
class FVector2D
{
	int X;
	int Y;
};
class Player
{
	FVector2D Position;

	void Move();
};

int PlayerX = 1;
int PlayerY = 1;

bool bIsRunning = true;
int Key;


int main()
{
	Player player;
	Player player2;
	

	while (bIsRunning)
	{
		Input();
		Process();
		Draw();
	}

	return 0;
}

void Input()
{
	Key = _getch();
	if (Key == 0x00 || Key == 0xE0)
	{
		//확장키의 경우 키를 하나 더 입력받는다.
		Key = _getch();
	}

}

void Process()
{
	switch (Key)
	{
		//up
	case 'W':
	case 'w':
	{
		MovePlayer(0, -1);
		break;
	}
	//down
	case 'S':
	case 's':
	{
		MovePlayer(0, 1);
		break;
	}
	//left
	case 'A':
	case 'a':
	{
		MovePlayer(-1, 0);
		break;
	}
	//right
	case 'D':
	case 'd':
	{
		MovePlayer(1, 0);
		break;
	}

	//quit
	case 'Q':
	case 'q':
	{
		bIsRunning = false;
		break;
	}
	}
}

void Draw()
{
	//화면을 지운다.
	system("cls");

	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			if (PlayerX == X && PlayerY == Y)
			{
				ChangeColor(87);
				cout << "P";
				ChangeColor(7);
				cout << " ";
			}
			else if (Map[Y][X] == 0)
			{
				cout << " " << " ";
			}
			else if (Map[Y][X] == 1)
			{
				cout << "X" << " ";
			}
			else if (Map[Y][X] == 9)
			{
				ChangeColor(87);
				cout << "G";
				ChangeColor(7);
				cout << " ";

			}
		}

		cout << endl;
	}
	if (bIsRunning == false)
	{
		cout << "끝";
	}

}


void MovePlayer(int XDirection, int YDirection)
{
	//새로 가볼 곳 계산
	int NewPlayerX = PlayerX + XDirection;
	int NewPlayerY = PlayerY + YDirection;

	//미리 가봄
	if (Map[NewPlayerY][NewPlayerX] == 0)
	{
		//이동
		PlayerX = NewPlayerX;
		PlayerY = NewPlayerY;
	}
	else if (Map[NewPlayerY][NewPlayerX] == 9)
	{
		bIsRunning = false;
	}
}

void ChangeColor(int Color)
{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}


