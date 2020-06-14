#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9

int boxStart(int x){
    if (0 <= x  && x <= 2) return 0;
    else if (3 <= x && x <= 5) return 3;
    else return 6;
}

bool isSafe(int **grid, int i, int j, int num){
    //Check the row
    for (int row = 0; row < 9; row++){
        if (grid[row][j] != num) continue;
        else return false;
    }
    //Check the column
    for (int column = 0; column < 9; column++){
        if (grid[i][column] != num) continue;
        else return false;
    }
    //Check the box
    int boxStartRow = boxStart(i);
    int boxStartCol = boxStart(j);
    for (int row = 0; row < 3; row++){
        for (int column = 0; column < 3; column++){
            if (grid[row + boxStartRow][column + boxStartCol] != num) continue;
            else return false;    
        }
    }
    return true;
}

bool sudokuSolver(int ***grid){
    for (int row = 0; row < 9; row++){
        for (int column = 0; column < 9; column++){

            if ((*grid)[row][column] == 0){

                for (int num = 1; num <= 9; num++){
                    if (isSafe((*grid), row, column, num)){
                        (*grid)[row][column] = num;
                        if (sudokuSolver(grid))
                            return true;
                        else
                            (*grid)[row][column] = 0;
                    }    
                }
                return false;
            }
        }
    }
    return true;
}

int main(void){
    //Malloc NxN array
    int **grid = (int **)malloc(N*sizeof(int *));
    for (int i = 0; i < N; i++)
        grid[i] = (int *)malloc(N*sizeof(int));

    printf("INPUT\n");
    int ch = getchar();
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (ch != ' '){
                grid[i][j] = ch-'0';
                printf("%d\t", grid[i][j]);
            }
            ch = getchar();
            ch = getchar();
        }
        printf("\n"); 
    }

    if (sudokuSolver(&grid)){
        printf("OUTPUT\n");
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                printf("%d\t", grid[i][j]);
            }
            printf("\n"); 
        }
    }
    else printf("There is no solution\n");

    return 0;
}