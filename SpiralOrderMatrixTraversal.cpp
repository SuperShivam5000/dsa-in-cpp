#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cin>>r;
    cin>>c;
    int a[r][c];
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>a[i][j];
        }
    }

    //Spiral Order Traversal
    int row_start=0, row_end=r-1, column_start=0, column_end=c-1;

    while(row_start<=row_end && column_start<=column_end){

        //for row_start
        for(int col = column_start; col<=column_end; col++){
            cout<<a[row_start][col]<<" ";
        }
        row_start++;

        //for column_end
        for(int row=row_start; row<=row_end; row++){
            cout<<a[row][column_end]<<" ";
        }
        column_end--;

        //for row_end
        for(int col = column_end; col>=column_start; col--){
            cout<<a[row_end][col]<<" ";
        }
        row_end--;

        //for column_start
        for(int row = row_end; row>=row_start; row--){
            cout<<a[row][column_start]<<" ";
        }
        column_start++;
    }
}