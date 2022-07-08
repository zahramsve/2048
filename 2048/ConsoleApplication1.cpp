#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;
//constants
const int i = 4;
const int j = 4;
void menu();
void firstmenu();
void secondmenu();
void thirdmenu();
void playgame();
int wincheck();
int main()
{
	menu();
	cout << "\nPress any key to close the game ...\n";
	getch();
}
// global variables : shared state
int arr[i][j];
bool gameOver, stuck, win;
int score;
bool moved;
char mov;
int x;
int s;
int z;
int y;
int stuckcheck();
void randup();
void setGlobals();
void gameLoop();
void render();
void leftmove();
void rightmove();
void upmove();
void downmove();
void sefrkonnde();
void menu()
{
	system("CLS");
	char inp;
	cout << "1. Start Game\n";
	cout << "2. Credits\n";
	cout << "3. Exit \n";
	cout << " Enter a number:\n";
	inp = getch();
	switch (inp)
	{
	case '1':
		firstmenu();
		break;
	case '2':
		secondmenu();
		break;
	case '3':
		break;
	default:
	{

		cout << "command was not valid\n";
		getch();
		menu();
	}
	}

}
void firstmenu()
{
	system("CLS");
	playgame();
	getch();
	menu();

}

void secondmenu()
{
	system("CLS");
	cout << "name: \n\t\"zahra sadat moosavi\"\n";
	cout << "student number:\n \t<990122680005>";
	getch();
	menu();

}

void playgame()
{
	system("CLS");
	setGlobals();
	sefrkonnde();
	render();
	while (!gameOver)
	{
		gameLoop();

		y = stuckcheck();
		if (y == 1)
		{
			cout << "\nSorry! you lose:(";
			gameOver = true;
			break;
		}
		x = wincheck();
		if (x == 1)
		{
			gameOver = true;
			break;
		}

	}
	getch();
	menu();

}
void sefrkonnde()
{
	for (int a = 0; a < 4; a++)
		for (int b = 0; b < 4; b++)
		{
			arr[a][b] = 0;
			arr[2][2] = 2;
		}
}
void setGlobals()
{
	gameOver = false;
	win = false;
	stuck = false;
	moved = false;
}

void input();
void update();
void render();
void gameLoop()
{
	input();
	update();
	render();

}

void input() {
	mov = getch();
}

void update() {
	if (mov == 'e' || mov == 'e')
	{

		gameOver = true;
		menu();
	}
	else if (mov == 'l' || mov == 'L')
		leftmove();

	else if (mov == 'r' || mov == 'R')
		rightmove();

	else if (mov == 'u' || mov == 'U')
		upmove();

	else if (mov == 'd' || mov == 'D')
		downmove();
	else {
		cout << "\ncommand was not valid!!";
		getch();
	}

}

int stuckcheck()
{
	z = 0;
	int t = 0, p = 0;
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 4; b++)
		{
			if (arr[a][b] != 0)
				t++;
		}
	}
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 4; b++)
		{
			if (arr[a][b] != arr[a][a + 1])
				p++;
			if (arr[a][b] != arr[a + 1][b])
				p++;
		}
		if (t == 16 && p == 24)
		{
			cout << "\nSorry! you lose:(";
			z = 1;
		}

	}

	return z;
}
int wincheck()
{
	s = 0;
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 4; b++)
			if (arr[a][b] == 2048)
			{
				s = 1;
				break;
			}
	}
	if (s == 1)
	{
		cout << "\ncongratulation! you won :D";
	}
	return s;
}

void rightmove()
{
	moved = false;
	for (int a = 0; a < 4; a++)
	{
		for (int b = 3; b > 0; b--)
		{
			int next = b - 1;
			for (; next > 0; next--)
				if (arr[a][next] > 0)
					break;

			if (arr[a][b] == 0)
			{
				if (arr[a][next] > 0)
				{
					arr[a][b] = arr[a][next];
					arr[a][next] = 0;
					b++;
					moved = true;
				}
			}
			else
			{
				if (arr[a][b] == arr[a][next])
				{
					arr[a][b] += arr[a][next];
					arr[a][next] = 0;
					moved = true;
				}
			}
		}
	}
	if (moved)
		randup();
}

void leftmove()
{
	moved = false;
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			int next = b + 1;
			for (; next < 3; next++)
				if (arr[a][next] > 0)
					break;

			if (arr[a][b] == 0)
			{
				if (arr[a][next] > 0)
				{
					arr[a][b] = arr[a][next];
					arr[a][next] = 0;
					moved = true;
					b--;
				}
			}
			else
			{
				if (arr[a][b] == arr[a][next])
				{
					arr[a][b] += arr[a][next];
					arr[a][next] = 0;
					moved = true;
				}
			}
		}
	}
	if (moved)
		randup();
}
void upmove()
{
	moved = false;
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			int next = b + 1;
			for (; next < 3; next++)
				if (arr[next][a] > 0)
					break;

			if (arr[b][a] == 0)
			{
				if (arr[next][a] > 0)
				{
					arr[b][a] = arr[next][a];
					arr[next][a] = 0;
					moved = true;
					b--;
				}
			}
			else
			{
				if (arr[b][a] == arr[next][a])
				{
					arr[b][a] += arr[next][a];
					arr[next][a] = 0;
					moved = true;
				}
			}
		}
	}
	if (moved)
		randup();
}

void downmove()
{
	moved = false;
	for (int a = 0; a < 4; a++)
	{
		for (int b = 3; b > 0; b--)
		{
			int next = b - 1;
			for (; next > 0; next--)
				if (arr[next][a] > 0)
					break;

			if (arr[b][a] == 0)
			{
				if (arr[next][a] > 0)
				{
					arr[b][a] = arr[next][a];
					arr[next][a] = 0;
					b++;
					moved = true;
				}
			}
			else
			{
				if (arr[b][a] == arr[next][a])
				{
					arr[b][a] += arr[next][a];
					arr[next][a] = 0;
					moved = true;
				}
			}
		}
	}
	if (moved)
		randup();
}
void randup()
{
	int a, b;
	srand(time(0));
	while (true)
	{
		a = rand() % 4;
		b = rand() % 4;
		if (arr[a][b] == 0)
		{
			arr[a][b] = 2;
			break;
		}
	}

}
void scoreupdate()
{

	int scoreup = 0;
	for (int a = 0; a < 4; a++)
		for (int b = 0; b < 4; b++)
			scoreup += arr[a][b];
	cout << "\nScore: " << scoreup << endl;
}

void render() {
	system("CLS");
	cout << "[2048 clone ===========]\n";
	cout << endl;
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 4; b++)
		{
			if (arr[a][b] == 0)
				cout << "[    ]";
			else if (arr[a][b] < 10)
				cout << "[ " << arr[a][b] << "  ]";
			else if (arr[a][b] < 100)
				cout << "[ " << arr[a][b] << " ]";
			else if (arr[a][b] < 1000)
				cout << "[ " << arr[a][b] << "]";
			else
				cout << "[" << arr[a][b] << "]";
		}
		cout << endl;
	}
	scoreupdate();
	cout << "[_Move:  L R U D |Exit: E]";
}
