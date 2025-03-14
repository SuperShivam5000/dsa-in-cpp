#include <iostream>
using namespace std;
void wavesort(int arr[],int n){
    int i,k;
    for(i=1;i<n;i=i+2){
        if(arr[i]>arr[i-1]){
            k=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=k;
        }
        if(arr[i]>arr[i+1]&&i<=n-2){
            k=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=k;
        }
    }
}

int main(){
    int arr[]={1,3,4,7,5,6,2};
    wavesort(arr,7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}