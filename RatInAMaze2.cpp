#include <iostream>
using namespace std;

void printmaze(int maze[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
}

void ratinamaze(int maze[4][4],string ans,bool visited[4][4], int sx, int sy, int ex, int ey){
    if(sx==ex && sy==ey){
        cout<<ans<<endl;
        return;
    }
    visited[sx][sy]=true;
    if(maze[sx][sy]==0) return;
    if(sy<3&&!visited[sx][sy+1])ratinamaze(maze,ans+"R",visited,sx,sy+1,ex,ey);
    if(sx<3&&!visited[sx+1][sy])ratinamaze(maze,ans+"D",visited,sx+1,sy,ex,ey);
    if(sy>0&&!visited[sx][sy-1])ratinamaze(maze,ans+"L",visited,sx,sy-1,ex,ey);
    if(sx>0&&!visited[sx-1][sy])ratinamaze(maze,ans+"U",visited,sx-1,sy,ex,ey);
    visited[sx][sy] = false;
}

int main(){
    int maze[4][4]={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    printmaze(maze);
    bool visited[4][4] = {false};
    ratinamaze(maze,"",visited,0,0,3,3);
}