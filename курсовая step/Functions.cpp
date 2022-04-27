#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "Functions.h"

using namespace std;

void SetColor(int ForgC)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;

}
enum { BLUE = 1, GREEN = 2, SKYBLUE = 3, RED = 4, VIOLET = 5, ORANGE = 6, WHITE = 7, GREY = 8 };
//-------------------FILTR-----------------------
bool isalpha_1(char a)
{
	char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz	";
	for (int i = 0; str[i]; i++)
		if (a == str[i])
			return 1;
	return 0;
}
bool isdigit_1(char a)
{
	char str[] = "0123456789";
	for (int i = 0; str[i]; i++)
		if (a == str[i])
			return 1;
	return 0;
}
bool ispunct_1(char a)
{
	char str[] = "!\"#$ % &'()*+,-./:;<=>?@[\\]^_`{|}~";
	for (int i = 0; str[i]; i++)
		if (a == str[i])
			return 1;
	return 0;
}
bool isalpharus(char a)
{
	char str[] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	for (int i = 0; str[i] ; i++)
		if (a == str[i])
			return 1;
	return 0;
}
//-----------------BATTLESHIP--------------------

void showfield(int f[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		if (i <= 8) cout << i + 1 << " ";
		else cout << i + 1;
		for (int j = 0; j < 10; j++)
		{
			if (f[i][j] == 3)
			{
				SetColor(RED), cout << "X ";
				if (f[i - 1][j] != 1 && f[i - 1][j] != 3) f[i - 1][j] = 2;
				if (f[i + 1][j] != 1 && f[i + 1][j] != 3)f[i + 1][j] = 2;
				if (f[i][j - 1] != 1 && f[i][j - 1] != 3)f[i][j - 1] = 2;
				if (f[i][j + 1] != 1 && f[i][j + 1] != 3)f[i][j + 1] = 2;
			}
			if (f[i][j] == 0)
				SetColor(SKYBLUE), cout << "* ";
			if (f[i][j] == 1)
				SetColor(WHITE), cout << "# ";
			if (f[i][j] == 2)
				SetColor(GREEN), cout << "+ ";
			SetColor(WHITE);
		}
		cout << endl;
	}
}
void showfield_pc(int f[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		if (i <= 8) cout << i + 1 << " ";
		else cout << i + 1;
		for (int j = 0; j < 10; j++)
		{
			if (f[i][j] == 3)
				SetColor(RED), cout << "X ";
			if (f[i][j] == 0 || f[i][j] == 1)
				SetColor(BLUE), cout << "- ";
			if (f[i][j] == 2)
				SetColor(GREEN), cout << "+ ";
			SetColor(WHITE);
		}
		cout << endl;
	}
}
bool BelongsToMatrix(int matrix[10][10], int cx, int cy)
{
	if (matrix[cx][cy] >= 0 && matrix[cx][cy] <= 9 ) return 1;
	return 0;
}
void generate_4deck(int matrix[10][10])
{
	int i = 0;
	do{
		int x = rand() % 10;
		int y = rand() % 10;
		if (matrix[x][y] == 0 && matrix[x - 1][y] == 0 && matrix[x - 2][y] == 0 && matrix[x - 3][y] == 0 && BelongsToMatrix(matrix,x-3,y))
		{
			if (matrix[x + 1][y] == 0 && matrix[x + 1][y + 1] == 0 && matrix[x - 3][y + 1] == 0 &&
				matrix[x + 1][y - 1] == 0 && matrix[x][y + 1] == 0 && matrix[x][y - 1] == 0 &&
				matrix[x - 1][y - 1] == 0 && matrix[x - 1][y + 1] == 0 && matrix[x - 2][y - 1] == 0 &&
				matrix[x - 2][y + 1] == 0 && matrix[x - 3][y - 1] == 0 && matrix[x - 4][y] == 0 &&
				matrix[x - 4][y - 1] == 0 && matrix[x - 4][y + 1] == 0)
			{
				matrix[x][y] = 1;
				matrix[x - 1][y] = 1;
				matrix[x - 2][y] = 1;
				matrix[x - 3][y] = 1;
				i++;
			}
		}
		else if (matrix[x][y] == 0 && matrix[x][y + 1] == 0 && matrix[x][y + 2] == 0 && matrix[x][y + 3] == 0 && BelongsToMatrix(matrix, x, y + 3))
		{
			if (matrix[x][y - 1] == 0 && matrix[x + 1][y - 1] == 0 && matrix[x - 1][y - 1] == 0 &&
				matrix[x + 1][y] == 0 && matrix[x - 1][y] == 0 && matrix[x + 1][y + 1] == 0 &&
				matrix[x - 1][y + 1] == 0 && matrix[x + 1][y + 2] == 0 && matrix[x - 1][y + 2] == 0 &&
				matrix[x + 1][y + 3] == 0 && matrix[x - 1][y + 3] == 0 && matrix[x + 1][y - 4] == 0 &&
				matrix[x - 1][y - 4] == 0 && matrix[x][y - 4] == 0)
			{
				matrix[x][y] = 1;
				matrix[x][y + 1] = 1;
				matrix[x][y + 2] = 1;
				matrix[x][y + 3] = 1;
				i++;
			}
		}
		else if (matrix[x][y] == 0 && matrix[x + 1][y] == 0 && matrix[x + 2][y] == 0 && matrix[x + 3][y] == 0 && BelongsToMatrix(matrix, x + 3, y))
		{
			if (matrix[x - 1][y] == 0 && matrix[x - 1][y - 1] == 0 && matrix[x - 1][y + 1] == 0 &&
				matrix[x][y - 1] == 0 && matrix[x][y + 1] == 0 && matrix[x + 1][y - 1] == 0 &&
				matrix[x + 1][y + 1] == 0 && matrix[x + 2][y - 1] == 0 && matrix[x + 2][y + 1] == 0 &&
				matrix[x + 3][y - 1] == 0 && matrix[x + 3][y + 1] == 0 && matrix[x + 4][y] == 0 && matrix[x + 4][y - 1]
				== 0 && matrix[x + 4][y + 1] == 0)
			{
				matrix[x][y] = 1;
				matrix[x + 1][y] = 1;
				matrix[x + 2][y] = 1;
				matrix[x + 3][y] = 1;
				i++;
			}
		}
		else if (matrix[x][y] == 0 && matrix[x][y - 1] == 0 && matrix[x][y - 2] == 0 && matrix[x][y - 3] == 0 && BelongsToMatrix(matrix, x , y - 3))
		{
			if (matrix[x][y + 1] == 0 && matrix[x + 1][y + 1] == 0 && matrix[x - 1][y + 1] == 0 &&
				matrix[x + 1][y] == 0 && matrix[x - 1][y] == 0 && matrix[x - 1][y - 1] == 0 &&
				matrix[x + 1][y - 1] == 0 && matrix[x - 1][y - 2] == 0 && matrix[x + 1][y - 2] == 0 &&
				matrix[x - 1][y - 3] == 0 && matrix[x + 1][y - 3] == 0 && matrix[x - 1][y - 4] == 0 &&
				matrix[x + 1][y - 4] == 0 && matrix[x][y - 4] == 0)
			{
				matrix[x][y] = 1;
				matrix[x][y - 1] = 1;
				matrix[x][y - 2] = 1;
				matrix[x][y - 3] = 1;
				i++;
			}
		}
	} while (i != 1);
}
void generate_3deck(int matrix[10][10])
{
	int i = 0;
	do{
		int x = rand() % 10;
		int y = rand() % 10;
		int var = rand() % 6;//вариантов расстановки (вверх,вниз,вправо,влево, вправо и влево, вверх и вниз)
		switch (var)
		{
		case 0:
			if (matrix[x][y] == 0 && matrix[x - 1][y] == 0 && matrix[x - 2][y] == 0 && BelongsToMatrix(matrix, x - 2, y))
			{
				if (matrix[x + 1][y] == 0 && matrix[x + 1][y + 1] == 0 && matrix[x - 3][y + 1] == 0 &&
					matrix[x + 1][y - 1] == 0 && matrix[x][y + 1] == 0 && matrix[x][y - 1] == 0 &&
					matrix[x - 1][y - 1] == 0 && matrix[x - 1][y + 1] == 0 && matrix[x - 2][y - 1] == 0 &&
					matrix[x - 2][y + 1] == 0 && matrix[x - 3][y] == 0 && matrix[x - 3][y - 1] == 0)
				{
					matrix[x][y] = 1;
					matrix[x - 1][y] = 1;
					matrix[x - 2][y] = 1;
					i++;
				}
			} break;
		case 1:
			if (matrix[x][y] == 0 && matrix[x][y + 1] == 0 && matrix[x][y + 2] == 0 && matrix[x][y + 2] && BelongsToMatrix(matrix, x, y + 2))
			{
				if (matrix[x][y - 1] == 0 && matrix[x + 1][y - 1] == 0 && matrix[x - 1][y - 1] == 0 &&
					matrix[x + 1][y] == 0 && matrix[x - 1][y] == 0 && matrix[x + 1][y + 1] == 0 &&
					matrix[x - 1][y + 1] == 0 && matrix[x + 1][y + 2] == 0 && matrix[x - 1][y + 2] == 0 &&
					matrix[x + 1][y + 3] == 0 && matrix[x][y + 3] == 0 && matrix[x - 1][y + 3] == 0)
				{
					matrix[x][y] = 1;
					matrix[x][y + 1] = 1;
					matrix[x][y + 2] = 1;
					i++;
				}
			} break;
		case 2:
			if (matrix[x][y] == 0 && matrix[x + 1][y] == 0 && matrix[x + 2][y] == 0 && BelongsToMatrix(matrix, x + 2, y))
			{
				if (matrix[x - 1][y] == 0 && matrix[x - 1][y - 1] == 0 && matrix[x - 1][y + 1] == 0 &&
					matrix[x][y - 1] == 0 && matrix[x][y + 1] == 0 && matrix[x + 1][y - 1] == 0 &&
					matrix[x + 1][y + 1] == 0 && matrix[x + 2][y - 1] == 0 && matrix[x + 2][y + 1] == 0 &&
					matrix[x + 3][y] == 0 && matrix[x + 3][y - 1] == 0 && matrix[x + 3][y + 1] == 0)
				{
					matrix[x][y] = 1;
					matrix[x + 1][y] = 1;
					matrix[x + 2][y] = 1;
					i++;
				}
			} break;
		case 3: 
			if (matrix[x][y] == 0 && matrix[x][y - 1] == 0 && matrix[x][y - 2] == 0 && BelongsToMatrix(matrix, x, y - 2))
			{
				if (matrix[x][y + 1] == 0 && matrix[x + 1][y + 1] == 0 && matrix[x - 1][y + 1] == 0 &&
					matrix[x + 1][y] == 0 && matrix[x - 1][y] == 0 && matrix[x - 1][y - 1] == 0 &&
					matrix[x + 1][y - 1] == 0 && matrix[x - 1][y - 2] == 0 && matrix[x + 1][y - 2] == 0 &&
					matrix[x][y - 3] == 0 && matrix[x - 1][y - 3] == 0 && matrix[x + 1][y - 3] == 0)
				{
					matrix[x][y] = 1;
					matrix[x][y - 1] = 1;
					matrix[x][y - 2] = 1;
					i++;
				}
			} break;
		case 4: 
			if (matrix[x][y] == 0 && matrix[x + 1][y] == 0 && matrix[x - 1][y] == 0 && BelongsToMatrix(matrix, x + 1, y) && BelongsToMatrix(matrix, x - 1, y))
			{
				if (matrix[x][y - 1] == 0 && matrix[x][y + 1] == 0 && matrix[x - 1][y - 1] == 0 &&
					matrix[x - 1][y + 1] == 0 && matrix[x + 1][y + 1] == 0 && matrix[x + 1][y - 1] == 0 &&
					matrix[x + 2][y] == 0 && matrix[x + 2][y - 1] == 0 && matrix[x + 2][y + 1] == 0 &&
					matrix[x - 2][y] == 0 && matrix[x - 2][y - 1] == 0 && matrix[x - 2][y + 1] == 0)
				{
					matrix[x][y] = 1;
					matrix[x + 1][y] = 1;
					matrix[x - 1][y] = 1;
					i++;
				}
			} break;
		case 5:
			if (matrix[x][y] == 0 && matrix[x][y + 1] == 0 && matrix[x][y - 1] == 0 && BelongsToMatrix(matrix, x, y + 1) && BelongsToMatrix(matrix, x, y - 1))
			{
				if (matrix[x][y + 2] == 0 && matrix[x][y - 2] == 0 && matrix[x + 1][y] == 0 &&
					matrix[x - 1][y] == 0 && matrix[x + 1][y + 1] == 0 && matrix[x - 1][y + 1] == 0 &&
					matrix[x + 1][y + 2] == 0 && matrix[x - 1][y + 2] == 0 && matrix[x + 1][y - 1] == 0 &&
					matrix[x - 1][y - 1] == 0 && matrix[x + 1][y - 2] == 0 && matrix[x - 1][y - 2] == 0)
				{
					matrix[x][y] = 1;
					matrix[x][y + 1] = 1;
					matrix[x][y - 1] = 1;
					i++;
				}
			} break;
		}
	} while (i != 2);
}
void generate_2deck(int matrix[10][10])
{
	int i = 0;
	do{
		int x = rand() % 10;
		int y = rand() % 10;
		int var = rand() % 4;
		switch (var)
		{
		case 0:
			if (matrix[x][y] == 0 && matrix[x - 1][y] == 0 && BelongsToMatrix(matrix, x - 1, y))//вверх
			{
				if (matrix[x + 1][y] == 0 && matrix[x + 1][y - 1] == 0 && matrix[x + 1][y + 1] == 0 &&
					matrix[x][y - 1] == 0 && matrix[x][y + 1] == 0 && matrix[x - 1][y - 1] == 0 &&
					matrix[x - 1][y + 1] == 0 && matrix[x - 2][y] == 0 && matrix[x - 2][y - 1] == 0 &&
					matrix[x - 2][y + 1] == 0)
				{
					matrix[x][y] = 1;
					matrix[x - 1][y] = 1;
					i++;
				}
			} break;
		case 1:
			if (matrix[x][y] == 0 && matrix[x][y + 1] == 0 && BelongsToMatrix(matrix, x , y + 1))//вправо
			{
				if (matrix[x - 1][y - 1] == 0 && matrix[x + 1][y - 1] == 0 && matrix[x][y - 1] == 0 &&
					matrix[x - 1][y] == 0 && matrix[x + 1][y] == 0 && matrix[x - 1][y + 1] == 0 &&
					matrix[x + 1][y + 1] == 0 && matrix[x - 1][y + 2] == 0 && matrix[x + 1][y + 2] == 0 &&
					matrix[x][y + 2] == 0)
				{
					matrix[x][y] = 1;
					matrix[x][y + 1] = 1;
					i++;
				}
			} break;
		case 2: 
			if (matrix[x][y] == 0 && matrix[x + 1][y] == 0 && BelongsToMatrix(matrix, x + 1, y))//вниз
			{
				if (matrix[x + 2][y] == 0 && matrix[x - 1][y] == 0 && matrix[x + 2][y - 1] == 0 &&
					matrix[x + 1][y - 1] == 0 && matrix[x][y - 1] == 0 && matrix[x - 1][y - 1] == 0 &&
					matrix[x + 2][y + 1] == 0 && matrix[x + 1][y + 1] == 0 && matrix[x][y + 1] == 0 &&
					matrix[x][y + 2] == 0)
				{
					matrix[x][y] = 1;
					matrix[x + 1][y] = 1;
					i++;
				}
			} break;
		case 3:
			if (matrix[x][y] == 0 && matrix[x][y - 1] == 0 && BelongsToMatrix(matrix, x, y - 1))//влево
			{
				if (matrix[x][y + 1] == 0 && matrix[x - 1][y + 1] == 0 && matrix[x + 1][y + 1] == 0 &&
					matrix[x + 1][y] == 0 && matrix[x - 1][y] == 0 && matrix[x - 1][y - 1] == 0 &&
					matrix[x + 1][y - 1] == 0 && matrix[x + 1][y - 2] == 0 && matrix[x][y - 2] == 0 &&
					matrix[x - 1][y - 2] == 0)
				{
					matrix[x][y] = 1;
					matrix[x][y - 1] = 1;
					i++;
				}
			} break;
		}
	} while (i != 3);//колличество кораблей
}
void generate_1deck(int matrix[10][10])
{
	int i = 0;
	do{
		int x = rand() % 10;
		int y = rand() % 10;
		if (matrix[x][y] == 0 && matrix[x - 1][y] == 0 && matrix[x - 1][y - 1] == 0 &&
			matrix[x - 1][y + 1] == 0 && matrix[x][y - 1] == 0 && matrix[x][y + 1] == 0
			&& matrix[x + 1][y] == 0 && matrix[x + 1][y - 1] == 0 && matrix[x + 1][y + 1] == 0)
		{
			matrix[x][y] = 1;
			i++;
		}
	} while (i != 4);
}
//в ручную
char buf[11] = "АБВГДЕЖЗИК";
char buf2[11] = "абвгдежзик";//глобально, надо не только в этой ф-ции
void init_kb(int field[10][10])
{
	int x, y;
	char chary;
	cout << "\nВаше поле:\n  А Б В Г Д Е Ж З И К\n";
	showfield(field);
	int i = 0;
	while (i != 1) {
	cout << "\nВведите координаты начала 4х палубного корабля - формат 'Число Буква': ";
	do cin >> x; while (x < 1 || x > 10);
	--x;//0-9 матрица
	do cin >> chary; while (chary != 'А' && chary != 'Б' && chary != 'В' && chary != 'Г' && chary != 'Д' && chary != 'Е' && chary != 'Ж' && chary != 'З' && chary != 'И' && chary != 'К'
		&& chary != 'а' && chary != 'б' && chary != 'в' && chary != 'г' && chary != 'д' && chary != 'е' && chary != 'ж' && chary != 'з' && chary != 'и' && chary != 'к');
	for (int i = 0; i < 10; i++)
	{
		if (chary == buf[i]) y = i;
		if (chary == buf2[i]) y = i;
	}
	cout << "\nВведите направление строения корабля: 0 - вверх, 1 - вниз, 2 - вправо, 3 - влево: ";
	int var;
	do cin >> var; while (var < 0 || var > 3);
	switch (var)
	{
	case 0:
		if (field[x][y] == 0 && field[x - 1][y] == 0 && field[x - 2][y] == 0 && field[x - 3][y] == 0 && BelongsToMatrix(field, x - 3, y))
		{
			if (field[x + 1][y] == 0 && field[x + 1][y + 1] == 0 && field[x - 3][y + 1] == 0 &&
				field[x + 1][y - 1] == 0 && field[x][y + 1] == 0 && field[x][y - 1] == 0 &&
				field[x - 1][y - 1] == 0 && field[x - 1][y + 1] == 0 && field[x - 2][y - 1] == 0 &&
				field[x - 2][y + 1] == 0 && field[x - 3][y - 1] == 0 && field[x - 4][y] == 0 &&
				field[x - 4][y - 1] == 0 && field[x - 4][y + 1] == 0)
			{
				field[x][y] = 1;
				field[x - 1][y] = 1;
				field[x - 2][y] = 1;
				field[x - 3][y] = 1;
				i++;
			}
		} break;
	case 1:
		if (field[x][y] == 0 && field[x + 1][y] == 0 && field[x + 2][y] == 0 && field[x + 3][y] == 0 && BelongsToMatrix(field, x + 3, y))
		{
			if (field[x - 1][y] == 0 && field[x - 1][y - 1] == 0 && field[x - 1][y + 1] == 0 &&
				field[x][y - 1] == 0 && field[x][y + 1] == 0 && field[x + 1][y - 1] == 0 &&
				field[x + 1][y + 1] == 0 && field[x + 2][y - 1] == 0 && field[x + 2][y + 1] == 0 &&
				field[x + 3][y - 1] == 0 && field[x + 3][y + 1] == 0 && field[x + 4][y] == 0 && field[x + 4][y - 1]
				== 0 && field[x + 4][y + 1] == 0)
			{
				field[x][y] = 1;
				field[x + 1][y] = 1;
				field[x + 2][y] = 1;
				field[x + 3][y] = 1;
				i++;
			}
		} break;
	case 2:
		if (field[x][y] == 0 && field[x][y + 1] == 0 && field[x][y + 2] == 0 && field[x][y + 3] == 0 && BelongsToMatrix(field, x, y + 3))
		{
			if (field[x][y - 1] == 0 && field[x + 1][y - 1] == 0 && field[x - 1][y - 1] == 0 &&
				field[x + 1][y] == 0 && field[x - 1][y] == 0 && field[x + 1][y + 1] == 0 &&
				field[x - 1][y + 1] == 0 && field[x + 1][y + 2] == 0 && field[x - 1][y + 2] == 0 &&
				field[x + 1][y + 3] == 0 && field[x - 1][y + 3] == 0 && field[x + 1][y - 4] == 0 &&
				field[x - 1][y - 4] == 0 && field[x][y - 4] == 0)
			{
				field[x][y] = 1;
				field[x][y + 1] = 1;
				field[x][y + 2] = 1;
				field[x][y + 3] = 1;
				i++;
			}
		} break;
	case 3:
		if (field[x][y] == 0 && field[x][y - 1] == 0 && field[x][y - 2] == 0 && field[x][y - 3] == 0 && BelongsToMatrix(field, x, y - 3))
		{
			if (field[x][y + 1] == 0 && field[x + 1][y + 1] == 0 && field[x - 1][y + 1] == 0 &&
				field[x + 1][y] == 0 && field[x - 1][y] == 0 && field[x - 1][y - 1] == 0 &&
				field[x + 1][y - 1] == 0 && field[x - 1][y - 2] == 0 && field[x + 1][y - 2] == 0 &&
				field[x - 1][y - 3] == 0 && field[x + 1][y - 3] == 0 && field[x - 1][y - 4] == 0 &&
				field[x + 1][y - 4] == 0 && field[x][y - 4] == 0)
			{
				field[x][y] = 1;
				field[x][y - 1] = 1;
				field[x][y - 2] = 1;
				field[x][y - 3] = 1;
				i++;
			}
		} break;
	}
	}
	system("cls");
	cout << "\nВаше поле:\n  А Б В Г Д Е Ж З И К\n";
	showfield(field);
	i = 0;
	while (i != 2) {
		cout << "\nВведите координаты начала 3х палубного корабля - формат 'Число Буква': ";
		do cin >> x; while (x < 1 || x > 10);
		--x;
		do cin >> chary; while (chary != 'А' && chary != 'Б' && chary != 'В' && chary != 'Г' && chary != 'Д' && chary != 'Е' && chary != 'Ж' && chary != 'З' && chary != 'И' && chary != 'К'
			&& chary != 'а' && chary != 'б' && chary != 'в' && chary != 'г' && chary != 'д' && chary != 'е' && chary != 'ж' && chary != 'з' && chary != 'и' && chary != 'к');
		
		for (int i = 0; i < 10; i++)
		{
			if (chary == buf[i]) y = i;
			if (chary == buf2[i]) y = i;
		}
		cout << "\nВведите направление строения корабля: 0 - вверх, 1 - вправо, 2 - вниз, 3 - влево, 4 - вверх и вниз, 5 - влево и вправо : ";
		int var;
		do cin >> var; while (var < 0 || var > 5);
		switch (var)
		{
		case 0:
			if (field[x][y] == 0 && field[x - 1][y] == 0 && field[x - 2][y] == 0 && BelongsToMatrix(field, x - 2, y))
			{
				if (field[x + 1][y] == 0 && field[x + 1][y + 1] == 0 && field[x - 3][y + 1] == 0 &&
					field[x + 1][y - 1] == 0 && field[x][y + 1] == 0 && field[x][y - 1] == 0 &&
					field[x - 1][y - 1] == 0 && field[x - 1][y + 1] == 0 && field[x - 2][y - 1] == 0 &&
					field[x - 2][y + 1] == 0 && field[x - 3][y] == 0 && field[x - 3][y - 1] == 0)
				{
					field[x][y] = 1;
					field[x - 1][y] = 1;
					field[x - 2][y] = 1;
					i++;
				}
			} break;
		case 1:
			if (field[x][y] == 0 && field[x][y + 1] == 0 && field[x][y + 2] == 0 && field[x][y + 2] && BelongsToMatrix(field, x, y + 2))
			{
				if (field[x][y - 1] == 0 && field[x + 1][y - 1] == 0 && field[x - 1][y - 1] == 0 &&
					field[x + 1][y] == 0 && field[x - 1][y] == 0 && field[x + 1][y + 1] == 0 &&
					field[x - 1][y + 1] == 0 && field[x + 1][y + 2] == 0 && field[x - 1][y + 2] == 0 &&
					field[x + 1][y + 3] == 0 && field[x][y + 3] == 0 && field[x - 1][y + 3] == 0)
				{
					field[x][y] = 1;
					field[x][y + 1] = 1;
					field[x][y + 2] = 1;
					i++;
				}
			} break;
		case 2:
			if (field[x][y] == 0 && field[x + 1][y] == 0 && field[x + 2][y] == 0 && BelongsToMatrix(field, x + 2, y))
			{
				if (field[x - 1][y] == 0 && field[x - 1][y - 1] == 0 && field[x - 1][y + 1] == 0 &&
					field[x][y - 1] == 0 && field[x][y + 1] == 0 && field[x + 1][y - 1] == 0 &&
					field[x + 1][y + 1] == 0 && field[x + 2][y - 1] == 0 && field[x + 2][y + 1] == 0 &&
					field[x + 3][y] == 0 && field[x + 3][y - 1] == 0 && field[x + 3][y + 1] == 0)
				{
					field[x][y] = 1;
					field[x + 1][y] = 1;
					field[x + 2][y] = 1;
					i++;
				}
			} break;
		case 3:
			if (field[x][y] == 0 && field[x][y - 1] == 0 && field[x][y - 2] == 0 && BelongsToMatrix(field, x, y - 2))
			{
				if (field[x][y + 1] == 0 && field[x + 1][y + 1] == 0 && field[x - 1][y + 1] == 0 &&
					field[x + 1][y] == 0 && field[x - 1][y] == 0 && field[x - 1][y - 1] == 0 &&
					field[x + 1][y - 1] == 0 && field[x - 1][y - 2] == 0 && field[x + 1][y - 2] == 0 &&
					field[x][y - 3] == 0 && field[x - 1][y - 3] == 0 && field[x + 1][y - 3] == 0)
				{
					field[x][y] = 1;
					field[x][y - 1] = 1;
					field[x][y - 2] = 1;
					i++;
				}
			} break;
		case 4:
			if (field[x][y] == 0 && field[x + 1][y] == 0 && field[x - 1][y] == 0 && BelongsToMatrix(field, x + 1, y) && BelongsToMatrix(field, x - 1, y))
			{
				if (field[x][y - 1] == 0 && field[x][y + 1] == 0 && field[x - 1][y - 1] == 0 &&
					field[x - 1][y + 1] == 0 && field[x + 1][y + 1] == 0 && field[x + 1][y - 1] == 0 &&
					field[x + 2][y] == 0 && field[x + 2][y - 1] == 0 && field[x + 2][y + 1] == 0 &&
					field[x - 2][y] == 0 && field[x - 2][y - 1] == 0 && field[x - 2][y + 1] == 0)
				{
					field[x][y] = 1;
					field[x + 1][y] = 1;
					field[x - 1][y] = 1;
					i++;
				}
			} break;
		case 5:
			if (field[x][y] == 0 && field[x][y + 1] == 0 && field[x][y - 1] == 0 && BelongsToMatrix(field, x, y + 1) && BelongsToMatrix(field, x, y - 1))
			{
				if (field[x][y + 2] == 0 && field[x][y - 2] == 0 && field[x + 1][y] == 0 &&
					field[x - 1][y] == 0 && field[x + 1][y + 1] == 0 && field[x - 1][y + 1] == 0 &&
					field[x + 1][y + 2] == 0 && field[x - 1][y + 2] == 0 && field[x + 1][y - 1] == 0 &&
					field[x - 1][y - 1] == 0 && field[x + 1][y - 2] == 0 && field[x - 1][y - 2] == 0)
				{
					field[x][y] = 1;
					field[x][y + 1] = 1;
					field[x][y - 1] = 1;
					i++;
				}
			} break;
		}
		system("cls");
		cout << "\nВаше поле:\n  А Б В Г Д Е Ж З И К\n";
		showfield(field);
	}
	i = 0;
	while (i != 3) {
		cout << "\nВведите координаты начала 2х палубного корабля - формат 'Число Буква': ";
		do cin >> x; while (x < 1 || x > 10);
		--x;
		do cin >> chary; while (chary != 'А' && chary != 'Б' && chary != 'В' && chary != 'Г' && chary != 'Д' && chary != 'Е' && chary != 'Ж' && chary != 'З' && chary != 'И' && chary != 'К'
			&& chary != 'а' && chary != 'б' && chary != 'в' && chary != 'г' && chary != 'д' && chary != 'е' && chary != 'ж' && chary != 'з' && chary != 'и' && chary != 'к');

		for (int i = 0; i < 10; i++)
		{
			if (chary == buf[i]) y = i;
			if (chary == buf2[i]) y = i;
		}
		cout << "\nВведите направление строения корабля: 0 - вверх, 1 - вправо, 2 - вниз, 3 - влево : ";
		int var;
		do cin >> var; while (var < 0 || var > 3);
		switch (var)
		{
		case 0:
			if (field[x][y] == 0 && field[x - 1][y] == 0 && BelongsToMatrix(field, x - 1, y))//вверх
			{
				if (field[x + 1][y] == 0 && field[x + 1][y - 1] == 0 && field[x + 1][y + 1] == 0 &&
					field[x][y - 1] == 0 && field[x][y + 1] == 0 && field[x - 1][y - 1] == 0 &&
					field[x - 1][y + 1] == 0 && field[x - 2][y] == 0 && field[x - 2][y - 1] == 0 &&
					field[x - 2][y + 1] == 0)
				{
					field[x][y] = 1;
					field[x - 1][y] = 1;
					i++;
				}
			} break;
		case 1:
			if (field[x][y] == 0 && field[x][y + 1] == 0 && BelongsToMatrix(field, x, y + 1))//вправо
			{
				if (field[x - 1][y - 1] == 0 && field[x + 1][y - 1] == 0 && field[x][y - 1] == 0 &&
					field[x - 1][y] == 0 && field[x + 1][y] == 0 && field[x - 1][y + 1] == 0 &&
					field[x + 1][y + 1] == 0 && field[x - 1][y + 2] == 0 && field[x + 1][y + 2] == 0 &&
					field[x][y + 2] == 0)
				{
					field[x][y] = 1;
					field[x][y + 1] = 1;
					i++;
				}
			} break;
		case 2:
			if (field[x][y] == 0 && field[x + 1][y] == 0 && BelongsToMatrix(field, x + 1, y))//вниз
			{
				if (field[x + 2][y] == 0 && field[x - 1][y] == 0 && field[x + 2][y - 1] == 0 &&
					field[x + 1][y - 1] == 0 && field[x][y - 1] == 0 && field[x - 1][y - 1] == 0 &&
					field[x + 2][y + 1] == 0 && field[x + 1][y + 1] == 0 && field[x][y + 1] == 0 &&
					field[x][y + 2] == 0)
				{
					field[x][y] = 1;
					field[x + 1][y] = 1;
					i++;
				}
			} break;
		case 3:
			if (field[x][y] == 0 && field[x][y - 1] == 0 && BelongsToMatrix(field, x, y - 1))//влево
			{
				if (field[x][y + 1] == 0 && field[x - 1][y + 1] == 0 && field[x + 1][y + 1] == 0 &&
					field[x + 1][y] == 0 && field[x - 1][y] == 0 && field[x - 1][y - 1] == 0 &&
					field[x + 1][y - 1] == 0 && field[x + 1][y - 2] == 0 && field[x][y - 2] == 0 &&
					field[x - 1][y - 2] == 0)
				{
					field[x][y] = 1;
					field[x][y - 1] = 1;
					i++;
				}
			} break;
		}
		system("cls");
		cout << "\nВаше поле:\n  А Б В Г Д Е Ж З И К\n";
		showfield(field);
	}
	i = 0;
	while (i != 4) {
		cout << "\nВведите координаты 1-палубного корабля - формат 'Число Буква': ";
		do cin >> x; while (x < 1 || x > 10);
		--x;
		do cin >> chary; while (chary != 'А' && chary != 'Б' && chary != 'В' && chary != 'Г' && chary != 'Д' && chary != 'Е' && chary != 'Ж' && chary != 'З' && chary != 'И' && chary != 'К'
			&& chary != 'а' && chary != 'б' && chary != 'в' && chary != 'г' && chary != 'д' && chary != 'е' && chary != 'ж' && chary != 'з' && chary != 'и' && chary != 'к');

		for (int i = 0; i < 10; i++)
		{
			if (chary == buf[i]) y = i;
			if (chary == buf2[i]) y = i;
		}
		if (field[x][y] == 0 && field[x - 1][y] == 0 && field[x - 1][y - 1] == 0 &&
			field[x - 1][y + 1] == 0 && field[x][y - 1] == 0 && field[x][y + 1] == 0
			&& field[x + 1][y] == 0 && field[x + 1][y - 1] == 0 && field[x + 1][y + 1] == 0)
		{
			field[x][y] = 1;
			i++;
		}
		system("cls");
		cout << "\nВаше поле:\n  А Б В Г Д Е Ж З И К\n";
		showfield(field);
	}
}
bool pc_shot(int field[10][10])
{
	int x, y;
	do {
		x = rand() % 10;
		y = rand() % 10;
	} while (field[x][y] == 3 || field[x][y] == 2);//защита от повторной атаки в корабль и в пустое место

		if (field[x][y] == 1)
		{
			field[x][y] = 3;
			int r = rand() % 4;
			switch (r)
			{
			case 0: x++; break;
			case 1: x--; break;
			case 2: y++; break;
			case 3: y--; break;
			}
			//можно, конечно, добавить чтоб сначала проверка есть ли на точке корабль и потом атаковать, кажется как в exe Саши
			//но по моему, это уровень "impossible". тут "на удачу" бьем по точкам рядом
			return true;
		}
		if (field[x][y] == 0)
		{
			field[x][y] = 2;
			return false;
		}
}
bool player_shot(int field[10][10])
{
	int x, y;
	char chary;
	do {
		cout << "\nВведите координаты по которым  будем стрелять (число буква) : ";
		do cin >> x; while (x < 1 || x > 10);
		--x;
		do cin >> chary; while (chary != 'А' && chary != 'Б' && chary != 'В' && chary != 'Г' && chary != 'Д' && chary != 'Е' && chary != 'Ж' && chary != 'З' && chary != 'И' && chary != 'К'
			&& chary != 'а' && chary != 'б' && chary != 'в' && chary != 'г' && chary != 'д' && chary != 'е' && chary != 'ж' && chary != 'з' && chary != 'и' && chary != 'к');
		for (int i = 0; i < 10; i++)
		{
			if (chary == buf[i]) y = i;
			if (chary == buf2[i]) y = i;
		}
	} while (field[x][y] == 3 || field[x][y] == 2);//защита от повторной атаки в корабль и в пустое место
	if (field[x][y] == 1)
	{
		field[x][y] = 3;
		cout << "Попал, еще!\n";
		return true;
	}
	if (field[x][y] == 0)
	{
		field[x][y] = 2;
		return false;
	}
}