// 7<9>1<2<3
#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

int binarysearch(int arr[], int start, int end, int key){
    int mid;
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) end=mid-1;
        else start=mid+1;
    }
    return -1;
}

int searchinrotatedsortedarray(int arr[], int n,int k){
    int start=0,end=n-1,mid;
    while(start<end){
        mid=(start+end)/2;
        if(arr[mid]>=arr[0])start=mid+1;
        else end=mid;
    }
    int pivot=start;
    int ans;
    if(arr[0]<=k&&k<=arr[pivot-1]) ans = binarysearch(arr,0,pivot-1,k);
    else ans = binarysearch(arr,pivot,n-1,k);
    return ans;
}

int main(){
    int arr[]={3,8,10,17,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result = searchinrotatedsortedarray(arr,n,2);
    cout<<"Result:- "<<result<<endl;
}