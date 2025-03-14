#include <iostream>
using namespace std;

int main(){
    int row=3,col=4;
    int arr[row][col]={1,2,3,4,5,6,7,8,9,10,11,12};
    int i,j;
    for(i=0;i<col;i++){
        for(j=0;j<row;j++){
            cout<<arr[j][i]<<" ";
        }
        i++;
        if(i>=col) break;
        for(j=row-1;j>=0;j--){
            cout<<arr[j][i]<<" ";
        }
    }
    cout<<endl;
}