#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

int squarerootusingbinarysearch(int arr[], int n, int key){
    int start=0,end=n-1,mid;
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) end=mid-1;
        else start=mid+1;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cin>>key;
    int result = squarerootusingbinarysearch(arr,n,key);
    cout<<"Result:- "<<result<<endl;
}