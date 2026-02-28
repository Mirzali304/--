#ifndef GAME_H
#define GAME_H

#define ROW 12
#define COL 12
#define EASY_COUNT 10
#define MIDDLE_COUNT 20
#define PLAY 1
#define PLAY2 2
#define EXIT 0

void InitBoard(char board[ROW][COL], int row, int col, char set);
void SetMine(char board[ROW][COL], int row, int col, int mine);
void Display(char board[ROW][COL], int row, int col);
int PlayerMove(char board[ROW][COL], char show[ROW][COL], int row, int col, int mine, int step);
int FindMine(char board[ROW][COL], char show[ROW][COL], int row, int col);

#endif // GAME_H
