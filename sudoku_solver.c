#include <stdio.h>
#include <stdbool.h>

#define N 9

int boxStart(int x){
    if (1 <= x <= 3) return 1;
    else if (4 <= x <= 6) return 4;
    else return 7;
}

bool isSafe(int grid[N][N], int i, int j){
    //Check the row
    for (int row = 0; row < 9; row++){
        if (row != i)
            if (grid[row][j] != grid[i][j]) continue;
        else return false;
    }
    //Check the column
    for (int column = 0; column < 9; column++){
        if (column != j)
            if (grid[i][column] != grid[i][j]) continue;
        else return false;
    }
    //Check the box
    int boxStartRow = boxStart(i);
    int boxStartCol = boxStart(j);
    for (int row = 0; row < 3; row++){
        for (int column = 0; column < 3; column++){
            if (row + boxStartRow != i && column + boxStartCol != j)
                if (grid[row + boxStartRow][column + boxStartCol] != grid[i][j]) continue;
                else return false;
        }
    }
    return true;
}

bool sudokuSolver(int *grid[][]){
    int num = 1;
    for (int row = 0; row < 9; row++){
        for (int column = 0; column < 9; column++){
            if (!(*grid)[row][column]){
                if (num == 9) num = 1;
                (*grid)[row][column] = num++;
                if (isSafe(grid, row, column))
                    if (sudokuSolver(grid)) return true;
            }
        }
    }
    return true;
}


int main(void){
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},   
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},   
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},   
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},   
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},   
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},   
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},   
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},   
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    return 0;
}