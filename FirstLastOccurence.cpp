#include <iostream>
using namespace std;

int firstoccurence(int arr[], int n,int size, int c){
    if(c==size) return -1;
    if(arr[0]==n) return c;
    else return firstoccurence(arr+1,n,size,c+1);
}

int lastoccurence(int arr[], int n,int size){
    if(size==0) return -1;
    if(arr[size-1]==n) return size-1;
    else return lastoccurence(arr,n,size-1);
    
}

int main(){
    int arr[]={1,2,5,4,2};
    cout<<firstoccurence(arr,2,5,0)<<endl;
    cout<<lastoccurence(arr,2,5)<<endl;
}