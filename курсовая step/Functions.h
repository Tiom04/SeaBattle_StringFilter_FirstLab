#pragma once
void SetColor(int ForgC);
//-------------------FILTR-----------------------
bool isalpha_1(char a);
bool isdigit_1(char a);
bool ispunct_1(char a);
bool isalpharus(char a);
//-----------------BATTLESHIP--------------------
bool BelongsToMatrix(int matrix[10][10], int cx, int cy);
void showfield(int f[10][10]);
void showfield_pc(int f[10][10]);
void generate_4deck(int matrix[10][10]);
void generate_3deck(int matrix[10][10]);
void generate_2deck(int matrix[10][10]);
void generate_1deck(int matrix[10][10]);
//
void init_kb(int field[10][10]);
//
bool pc_shot(int field[10][10]);//1 если попал, 0 если промазал
bool player_shot(int field[10][10]);