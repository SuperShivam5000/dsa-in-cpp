#include <iostream>
using namespace std;

int main(){
    int row=3,col=3;
    int arr[row][col]={ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int count=0,total=row*col;
    int startingrow=0,endingrow=row-1,startingcol=0,endingcol=col-1;
    while(count<total){
        for(int i=startingcol;i<=endingcol&&count<total;i++){
            cout<<arr[startingrow][i];
            count++;
        }
        startingrow++;
        for(int i=startingrow;i<=endingrow&&count<total;i++){
            cout<<arr[i][endingcol];
            count++;
        }
        endingcol--;
        for(int i=endingcol;i>=startingcol&&count<total;i--){
            cout<<arr[endingrow][i];
            count++;
        }
        endingrow--;
        for(int i=endingrow;i>=startingrow&&count<total;i--){
            cout<<arr[i][startingcol];
            count++;
        }
        startingcol++;
    }
}