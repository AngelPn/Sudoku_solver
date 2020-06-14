#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9

int boxStart(int x){
    if (1 <= x  && x <= 3) return 1;
    else if (4 <= x && x <= 6) return 4;
    else return 7;
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

            if (!(*grid)[row][column]){

                for (int num = 1; num <= 9; num++){
                    if (isSafe((*grid), row, column, num)){
                        (*grid)[row][column] = num++;
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
    int array[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},   
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},   
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},   
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},   
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},   
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},   
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},   
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},   
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    printf("%d\n", array[8][4]);


    int i,j;
    printf("INPUT\n");
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            grid[i][j] = array[i][j];
            printf("%d\t", grid[i][j]);
        }
        printf("\n"); 
    }

    if (sudokuSolver(&grid)){
        printf("OUTPUT\n");
        for (i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                printf("%d\t", grid[i][j]);
            }
            printf("\n"); 
        }
    }
    else printf("There is no solution\n");

    return 0;
}