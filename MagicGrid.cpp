#include <bits/stdc++.h>
using namespace std;

bool distinct(vector<int> temp){
    for(int i=0;i<temp.size();i++){
        if(temp[i]>9||temp[i]<=0) return false;
    }
    int cache[10]={0};
    for(int i=0;i<temp.size();i++){
        cache[temp[i]]++;
    }
    for(int i=0;i<10;i++){
        if(cache[i]>1) return false;
    }
    return true;
}

bool checkMagic(vector<int> temp){
    if(!distinct(temp)) return false;
    
    int s = temp[0] + temp[1] + temp[2];

    int d1 = temp[0] + temp[4] + temp[8];
    int d2 = temp[2] + temp[4] + temp[6];

    int r1 = temp[0] + temp[1] + temp[2];
    int r2 = temp[3] + temp[4] + temp[5];
    int r3 = temp[6] + temp[7] + temp[8];

    int c1 = temp[0] + temp[3] + temp[6];
    int c2 = temp[1] + temp[4] + temp[7];
    int c3 = temp[2] + temp[5] + temp[8];
    
    if(s == d1 && s == d2 && s == r1 && s == r2 && s == r3 && s == c1 && s == c2 && s == c3) return true;
    else return false;
}

int numMagicSquaresInside(vector<vector<int>> &grid)
{
    int c=0;
    int row = grid.size();
    int col = grid[0].size();
    for (int i = 0; i < row-2; i++)
    {
        for (int j = 0; j < col-2; j++)
        {
            vector<int> temp;
            for(int k=i;k<i+3;k++){
                for(int l=j;l<j+3;l++){
                    temp.push_back(grid[k][l]);
                }
            }
            if(checkMagic(temp)) c++;
        }
    }
    return c;
}
int main()
{
    vector<vector<int>> grid = {{5,5,5},{5,5,5},{5,5,5}};
    int result=numMagicSquaresInside(grid);
    cout<<"C:"<<result<<endl;
    return 0;
}