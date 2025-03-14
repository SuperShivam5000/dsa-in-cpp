#include <bits/stdc++.h>
using namespace std;

int isSorted(int arr[], int n){
    if(n==1) return true;
    return (arr[0]<=arr[1]&&isSorted(arr+1,n-1));
}

int main(){
    int arr[]={1,2,3,4,5,6,7,14,9,10,11,12,13};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<isSorted(arr,n)<<endl;
}