#include <iostream>
using namespace std;

int main(){
    int row=4,col=3;
    int arr[row][col]={ {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };
    int k=8;
    int s=0;
    int e=row*col-1;
    while(s<=e){
        int mid=(s+e)/2;
        int midrow=mid/col;
        int midcol=mid%col;
        if(arr[midrow][midcol]==k) {cout<<"Found!"<<endl; return 1;}
        else if(arr[midrow][midcol]>k) e=mid-1;
        else s=mid+1;
    }
    cout<<"Not Found!"<<endl;
}