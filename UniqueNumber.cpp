#include <iostream>
using namespace std;

int main(){
    int arr[]={1,5,3,4,3,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int xorsum=0;
    int i;
    for(i=0;i<n;i++){
        xorsum=xorsum^arr[i];
    }
    cout<<xorsum<<endl;
}