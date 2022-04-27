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
	char str[] = "�������������������������������������Ũ��������������������������";
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
		int var = rand() % 6;//��������� ����������� (�����,����,������,�����, ������ � �����, ����� � ����)
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
			if (matrix[x][y] == 0 && matrix[x - 1][y] == 0 && BelongsToMatrix(matrix, x - 1, y))//�����
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
			if (matrix[x][y] == 0 && matrix[x][y + 1] == 0 && BelongsToMatrix(matrix, x , y + 1))//������
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
			if (matrix[x][y] == 0 && matrix[x + 1][y] == 0 && BelongsToMatrix(matrix, x + 1, y))//����
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
			if (matrix[x][y] == 0 && matrix[x][y - 1] == 0 && BelongsToMatrix(matrix, x, y - 1))//�����
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
	} while (i != 3);//����������� ��������
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
//� ������
char buf[11] = "����������";
char buf2[11] = "����������";//���������, ���� �� ������ � ���� �-���
void init_kb(int field[10][10])
{
	int x, y;
	char chary;
	cout << "\n���� ����:\n  � � � � � � � � � �\n";
	showfield(field);
	int i = 0;
	while (i != 1) {
	cout << "\n������� ���������� ������ 4� ��������� ������� - ������ '����� �����': ";
	do cin >> x; while (x < 1 || x > 10);
	--x;//0-9 �������
	do cin >> chary; while (chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�'
		&& chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�');
	for (int i = 0; i < 10; i++)
	{
		if (chary == buf[i]) y = i;
		if (chary == buf2[i]) y = i;
	}
	cout << "\n������� ����������� �������� �������: 0 - �����, 1 - ����, 2 - ������, 3 - �����: ";
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
	cout << "\n���� ����:\n  � � � � � � � � � �\n";
	showfield(field);
	i = 0;
	while (i != 2) {
		cout << "\n������� ���������� ������ 3� ��������� ������� - ������ '����� �����': ";
		do cin >> x; while (x < 1 || x > 10);
		--x;
		do cin >> chary; while (chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�'
			&& chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�');
		
		for (int i = 0; i < 10; i++)
		{
			if (chary == buf[i]) y = i;
			if (chary == buf2[i]) y = i;
		}
		cout << "\n������� ����������� �������� �������: 0 - �����, 1 - ������, 2 - ����, 3 - �����, 4 - ����� � ����, 5 - ����� � ������ : ";
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
		cout << "\n���� ����:\n  � � � � � � � � � �\n";
		showfield(field);
	}
	i = 0;
	while (i != 3) {
		cout << "\n������� ���������� ������ 2� ��������� ������� - ������ '����� �����': ";
		do cin >> x; while (x < 1 || x > 10);
		--x;
		do cin >> chary; while (chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�'
			&& chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�');

		for (int i = 0; i < 10; i++)
		{
			if (chary == buf[i]) y = i;
			if (chary == buf2[i]) y = i;
		}
		cout << "\n������� ����������� �������� �������: 0 - �����, 1 - ������, 2 - ����, 3 - ����� : ";
		int var;
		do cin >> var; while (var < 0 || var > 3);
		switch (var)
		{
		case 0:
			if (field[x][y] == 0 && field[x - 1][y] == 0 && BelongsToMatrix(field, x - 1, y))//�����
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
			if (field[x][y] == 0 && field[x][y + 1] == 0 && BelongsToMatrix(field, x, y + 1))//������
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
			if (field[x][y] == 0 && field[x + 1][y] == 0 && BelongsToMatrix(field, x + 1, y))//����
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
			if (field[x][y] == 0 && field[x][y - 1] == 0 && BelongsToMatrix(field, x, y - 1))//�����
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
		cout << "\n���� ����:\n  � � � � � � � � � �\n";
		showfield(field);
	}
	i = 0;
	while (i != 4) {
		cout << "\n������� ���������� 1-��������� ������� - ������ '����� �����': ";
		do cin >> x; while (x < 1 || x > 10);
		--x;
		do cin >> chary; while (chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�'
			&& chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�');

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
		cout << "\n���� ����:\n  � � � � � � � � � �\n";
		showfield(field);
	}
}
bool pc_shot(int field[10][10])
{
	int x, y;
	do {
		x = rand() % 10;
		y = rand() % 10;
	} while (field[x][y] == 3 || field[x][y] == 2);//������ �� ��������� ����� � ������� � � ������ �����

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
			//�����, �������, �������� ���� ������� �������� ���� �� �� ����� ������� � ����� ���������, ������� ��� � exe ����
			//�� �� �����, ��� ������� "impossible". ��� "�� �����" ���� �� ������ �����
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
		cout << "\n������� ���������� �� �������  ����� �������� (����� �����) : ";
		do cin >> x; while (x < 1 || x > 10);
		--x;
		do cin >> chary; while (chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�'
			&& chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�' && chary != '�');
		for (int i = 0; i < 10; i++)
		{
			if (chary == buf[i]) y = i;
			if (chary == buf2[i]) y = i;
		}
	} while (field[x][y] == 3 || field[x][y] == 2);//������ �� ��������� ����� � ������� � � ������ �����
	if (field[x][y] == 1)
	{
		field[x][y] = 3;
		cout << "�����, ���!\n";
		return true;
	}
	if (field[x][y] == 0)
	{
		field[x][y] = 2;
		return false;
	}
}