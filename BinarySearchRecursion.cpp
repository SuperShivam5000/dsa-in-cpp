#include <bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int n, int s, int e){
    if(s>e) return -1;

    int mid=(s+e)/2;
    if(arr[mid]==n) return mid;
    else if(arr[mid]<n)s=mid+1;
    else if(arr[mid]>n)e=mid-1;
    binarysearch(arr,n,s,e);
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13};
    int size=sizeof(arr)/sizeof(arr[0]);
    int n=-2;
    cout<<binarysearch(arr,n,0,size-1)<<endl;
}