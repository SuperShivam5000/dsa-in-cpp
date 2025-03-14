#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int arr[]={17,6,2,6,9,2,17,17,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int cache[64];
    int i,ele,pos;
    for(i=0;i<64;i++) cache[i]=0;
    for(i=0;i<n;i++){
        ele=arr[i];
        pos=0;
        while(ele>0){
            if((ele&1)==1) cache[pos]++;
            pos++;
            ele=ele>>1;
        }
    }
    for(i=0;i<64;i++) cache[i]=cache[i]%3;
    int realno=0;
    for(i=0;i<64;i++) realno=realno+cache[i]*pow(2,i);
    cout<<realno<<endl;
}