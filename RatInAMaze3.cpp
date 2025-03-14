#include <bits/stdc++.h>

void solve(vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<int>> &visited, string temp, int x, int y){
    if(x==n-1 && y==n-1){
        ans.push_back(temp);
        return;
    }

    visited[x][y]=1; //mark visited
    //remember: adjust y for moving left&right, and adjust x for moving up&down
    if(x+1<n && !visited[x+1][y] && arr[x+1][y]==1) solve(arr,n,ans,visited,temp+'D',x+1,y); //Down
    if(y-1>=0 && !visited[x][y-1] && arr[x][y-1]==1) solve(arr,n,ans,visited,temp+'L',x,y-1); //Left
    if(y+1<n && !visited[x][y+1] && arr[x][y+1]==1) solve(arr,n,ans,visited,temp+'R',x,y+1); //Right
    if(x-1>=0 && !visited[x-1][y] && arr[x-1][y]==1) solve(arr,n,ans,visited,temp+'U',x-1,y); //Up
    visited[x][y]=0; //backtrack
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) { //This is the one that is not solved locally and tested on testcases. 
    vector<vector<int>> visited(n,(vector<int>(n,0)));
    vector<string> ans;
    if (arr[0][0] == 1) solve(arr,n,ans,visited,"",0,0); //remember to test if first block is valid before solving
    return ans; 
}