#include <bits/stdc++.h> 

bool isSafe(vector<vector<int>> &board, int x, int y, int n) { //This function can be optimized from o(n) to o(1) using Hashmaps
    // Check xth collumn
    for (int i = 0; i < n; i++) {
        if (board[x][i] == 1) return false;
    }

    // Check main diagonal (top-left to bottom-right)
    int i = x, j = y;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) return false;
        i--;
        j--;
    }

    // Check other diagonal (top-right to bottom-left)
    i = x, j = y;
    while (i < n && j >= 0) {
        if (board[i][j] == 1) return false;
        i++;
        j--;
    }

    return true;
}

void squeeze(vector<vector<int>> &board, vector<vector<int>> &result, int n){
	vector<int> temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]);
		}
	}
	result.push_back(temp);
}
void solve(vector<vector<int>> &board, int n, int col, vector<vector<int>> &result){
	if(col==n) {
		squeeze(board,result,n); 
		return;
	}

	for(int row=0;row<n;row++){
		if(isSafe(board,row,col, n)){
			board[row][col]=1;
			solve(board,n,col+1, result);
			board[row][col]=0;
		}
	}
}

vector<vector<int>> nQueens(int n) //This is the one that is not solved locally and tested on testcases. TC = o(n!)
{
	vector<vector<int>> board(n,vector<int>(n,0));
	vector<vector<int>> result;
	solve(board,n,0,result);
	return result;
}