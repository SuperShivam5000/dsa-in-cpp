#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

int peakinmountainarray(int arr[], int n){
    int start=0,end=n-1,mid;
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]) return arr[mid];
        else if(arr[mid-1]<arr[mid]&&arr[mid]<arr[mid+1]) start=mid+1;
        else if(arr[mid-1]>arr[mid]&&arr[mid]>arr[mid+1]) end=mid-1;
    }
    return -1;
}

int main(){
    int arr[]={1,2,3,4,3,2,1,0,-1,-2,-3,-4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result = peakinmountainarray(arr,n);
    cout<<"Result:- "<<result<<endl;
}