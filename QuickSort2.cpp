#include <iostream>
using namespace std;

int partition(int arr[],int s,int e){
    int pivot=arr[s];
    int c=s;
    for(int i=s;i<=e;i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[c]);
            c++;
        }
    }
    swap(arr[s],arr[--c]);
    return c;
}

void quicksort(int arr[],int s,int e){
    if(s<e){
        int pi=partition(arr,s,e);
        quicksort(arr,s,pi-1);
        quicksort(arr,pi+1,e);
    }
}

int main(){
    int arr[]={5,2,4,6,7,1,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,size-1);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}