#include <bits/stdc++.h>
using namespace std;

void printarr(int arr[],int size, int start=0){ //default value of start=0 //should be rightmost parameters
    for(int i=start;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={1,2,3,4,5};
    int size=5;
    printarr(arr,size); //start=0(default)
    printarr(arr,size,2); //start=2
}