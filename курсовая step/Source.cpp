#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <conio.h>
#include "Functions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	SetConsoleCP (1251);
	SetConsoleOutputCP (1251);
	enum { BLUE = 1, GREEN = 2, SKYBLUE = 3, RED = 4, VIOLET = 5, ORANGE = 6, WHITE = 7, GREY = 8 };
	{
		// ФИЛЬТР
		char keyboard_string[50] = "01 Hello, ворлд!!?? 255.";
		cout << "Введите строку: ";
		cin.getline(keyboard_string, sizeof(keyboard_string));
		bool a = 0, d = 0, p = 0, ar = 0; //alpha,digit,punct,alpha-rus   flags
		int var;
		do {
			
		for (int i = 0; i < strlen(keyboard_string); i++)
		{
			if (isalpha_1(keyboard_string[i]))
			{
				if (!a)
				{
					SetColor(BLUE);
					cout << keyboard_string[i];
				}
				else cout << ' ';
			}
			if (isdigit_1(keyboard_string[i]))
			{
				if (!d)
				{
					SetColor(RED);
					cout << keyboard_string[i];
				}
				else cout << ' ';
			}
			if (ispunct_1(keyboard_string[i]))
			{
				if (!p)
				{
					SetColor(VIOLET);
					cout << keyboard_string[i];
				}
				else cout << ' ';
			}
			if (isalpharus(keyboard_string[i]))
			{
				if (!ar)
				{
					SetColor(ORANGE);
					cout << keyboard_string[i];
				}
				else cout << ' ';
			}
		}
		SetColor(WHITE);
			cout << "\n\n\tМеню фильтрации:\n1. Латиница\n2. Цифры\n3. Пунктуация\n"
				<< "4. Кириллица\n5. Выход из меню\n\tВвод: ";
			do cin >> var; while (var < 1 || var > 5);

		switch (var)
		{
		case 1:
		{
			/*if (a) a = 0;
			else a = 1;*/
			a = !a;
			//
		} break;
		case 2:
		{
			if (d) d = 0;
			else d = 1;
		} break;
		case 3:
		{
			if (p) p = 0;
			else p = 1;
		} break;
		case 4:
		{
			if (ar) ar = 0;
			else ar = 1;
		} break;
		default: continue;
		}
		system("cls");
		} while (var != 5);
	}
	{
		//МОРСКОЙ БОЙ

#define Cheats //показ поля пк с кораблями

    #define MATRIXSIZE 10
//
		int player_field[MATRIXSIZE][MATRIXSIZE]{ 0 }, computer_field[MATRIXSIZE][MATRIXSIZE]{ 0 };
		bool choose;
		bool winflag_us = 1, winflag_pc = 1;

		generate_4deck(computer_field);
		generate_3deck(computer_field);
		generate_2deck(computer_field);
		generate_1deck(computer_field);

		cout << "\nИгра \"Морской бой\"\nВыберите расставлять корабли в ручную (0) или автоматически (1)";
		SetColor(RED);
		cout << "\n !!! Настоятельно рекомендуется довериться авторасстановке !!!";
		SetColor(WHITE);
		cout << "\nВвод: ";

		do cin >> choose; while (choose < 0 || choose > 1);
		if (choose)
		{
			generate_4deck(player_field);
			generate_3deck(player_field);
			generate_2deck(player_field);
			generate_1deck(player_field);
		}
		else
		{
			init_kb(player_field);
		}
		system("cls");

do {
			
	system("cls");
			cout << "\nВаше поле:\n  А Б В Г Д Е Ж З И К\n";
			showfield(player_field);
			cout << endl << endl << "Поле ПК:\n  А Б В Г Д Е Ж З И К\n";
			showfield_pc(computer_field);


#ifdef Cheats //строка 99
			cout << endl;
			showfield(computer_field);
#endif

			bool p;
			do { 
				cout << "\nВаш ход\n";
					if (player_shot(computer_field)) p = true; 
					else p = false; 
			} while (p);

			do { cout << "\nХодит ПК";
			Sleep(500);
			if (pc_shot(player_field)) p = true; 
			else p = false; 
			} while (p);

			for(int i = 0; i < MATRIXSIZE; i++)
				for (int j = 0; j < MATRIXSIZE; j++)
				{
					if (player_field[i][j] == 1)
					{
						winflag_pc = 0;
						break;
					}
					if (computer_field[i][j] == 1)
					{
						winflag_us = 0;
						break;
					}
				}

		} while (winflag_us != 1 || winflag_pc != 1);

		if (winflag_us == 1) cout << "\nВыйграл пользователь!";
		if (winflag_pc == 1) cout << "\nВыйграл пк!";
	}

	
	_getch();
	return 0;
}