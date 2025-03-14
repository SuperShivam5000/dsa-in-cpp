#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

void bubblesort(int arr[],int n){
    if(n==1) return;
    for (int i = 0; i < n-1; i++) {
        if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
    }
    bubblesort(arr,n-1);
}

int main(){
    int arr[] = {1,6,4,7,3,2,9,6,7,4,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<endl;
    }
}