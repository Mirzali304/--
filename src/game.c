#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col, char set) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = set;
        }
    }
}

void SetMine(char board[ROW][COL], int row, int col, int mine) {
    while (mine) {
        int x = rand() % row;
        int y = rand() % col;
        if (board[x][y] != '*') {
            board[x][y] = '*';
            mine--;
        }
    }
}

void Display(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int FindMine(char board[ROW][COL], char show[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == '*' && show[i][j] == '0') {
                return 1; // Game over
            }
        }
    }
    return 0; // Game continues
}

int PlayerMove(char board[ROW][COL], char show[ROW][COL], int row, int col, int mine, int step) {
    int x, y;
    printf("请输入你要选择的坐标 (行 列): ");
    scanf("%d %d", &x, &y);
    
    if (x < 0 || x >= row || y < 0 || y >= col) {
        printf("坐标无效，请重新输入。\n");
        return 0; // Continue the game
    }
    
    if (board[x][y] == '*') {
        return 1; // Hit a mine
    } else {
        show[x][y] = board[x][y]; // Reveal the cell
    }
    
    return 0; // Continue the game
}