#include <stdio.h>
#define ROWS 40
#define COLS 40

void display(char[ROWS][COLS], int, int);
void create_board(char[ROWS][COLS], int, int);
int get_input(char[ROWS][COLS], char[ROWS][COLS], int, int);
void calculate(char[ROWS][COLS], char[ROWS][COLS], int, int);
int count_neighbors(char[ROWS][COLS], int, int);
void add_x(char[ROWS][COLS], int, int);
void remove_x(char[ROWS][COLS], int, int);
void update(char[ROWS][COLS], char[ROWS][COLS], int, int);
void continuous_update(char[ROWS][COLS], char[ROWS][COLS], int, int);
void interactive_init(char[ROWS][COLS], char[ROWS][COLS], int, int);
void batch_init(char[ROWS][COLS], char[ROWS][COLS], int, int, int, char[]);
void get_file_input(char[], char[ROWS][COLS], char[ROWS][COLS], int, int);