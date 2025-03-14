#include <bits/stdc++.h>

bool isSafe(vector<vector<int>>& sudoku, int row, int col, int data){
    //row and column check
    for(int i=0;i<9;i++){
        if(sudoku[row][i]==data || sudoku[i][col]==data) return false;
    }

    //subgrid check
    int subgridX=(row/3)*3;
    int subgridY=(col/3)*3;
    for(int i=subgridX ; i<subgridX+3 ; i++){
        for(int j=subgridY ; j<subgridY+3 ; j++){
            if(sudoku[i][j]==data) return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& sudoku){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j]==0){
                for(int k=1;k<=9;k++){
                    if(isSafe(sudoku,i,j,k)){
                        sudoku[i][j]=k; //add number
                        bool nextSolutionExists=solve(sudoku); //make call after adding number
                        if(nextSolutionExists) return true; //solution is valid, return true
                        else sudoku[i][j]=0; //backtrack
                    }
                }
                return false; //if no number from 1 to 9 can be inserted return false
            }
        }
    }
    return true; //no zero elements are left so return true
}

void solveSudoku(vector<vector<int>>& sudoku) //TC = o(9^m) where m is number of empty cells
{
	solve(sudoku);
}