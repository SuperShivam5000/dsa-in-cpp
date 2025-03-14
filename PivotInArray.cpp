// 7<9>1<2<3
#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

int pivotelement(int arr[], int n){
    int start=0,end=n-1,mid;
    while(start<end){
        mid=(start+end)/2;
        if(arr[mid]>=arr[0])start=mid+1;
        else end=mid;
    }
    return start;
}

int main(){
    int arr[]={3,8,10,17,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result = pivotelement(arr,n);
    cout<<"Result:- "<<result<<endl;
}