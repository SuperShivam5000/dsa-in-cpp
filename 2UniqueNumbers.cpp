#include <iostream>
using namespace std;

int hasBit(int i, int n){
    n=n>>i;
    n=n&1;
    return n;
}

int main(){
    int arr[]={1,5,3,4,7,3,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int xorsum=0;
    int i;
    for(i=0;i<n;i++){
        xorsum=xorsum^arr[i];
    }
    int oldxor=xorsum;
    //find rightmost set bit
    int pos=0;
    while(true){
        if(xorsum&1==1) break;
        pos++;
        xorsum=xorsum>>1;
    }
    int newxor=0;
    for(i=0;i<n;i++){
        if(hasBit(pos,arr[i])) newxor=newxor^arr[i];
    }
    cout<<newxor<<endl;
    cout<<(newxor^oldxor)<<endl;
}