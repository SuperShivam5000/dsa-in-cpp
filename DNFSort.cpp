#include <iostream>
using namespace std;
void dnfsort(int arr[],int n){
    int low=0,mid=0,high=n-1,temp;
    while(mid!=high){
        if(arr[mid]==1) mid++;
        else if(arr[mid]==2){
            temp=arr[high];
            arr[high]=arr[mid];
            arr[mid]=temp;
            high--;
        } else {
            temp=arr[low];
            arr[low]=arr[mid];
            arr[mid]=temp;
            mid++;
            low++;
        }
    }
}

int main(){
    int arr[]={1,0,2,1,0,1,2,2,1};
    dnfsort(arr,9);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}