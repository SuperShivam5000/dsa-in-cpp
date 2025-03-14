#include <iostream>
using namespace std;

int main(){
    int n=1000;
    n++;
    int arr[n];
    int i,j;
    for(i=0;i<n;i++) arr[i]=0;
    for(i=2;i<n;i++){
        if(arr[i]==1) continue;
        for(j=i*i;j<n;j=j+i){
            arr[j]=1;
        }
    }
    for(i=2;i<n;i++){
        if(arr[i]==0) cout<<i<<" ";
    }
    cout<<endl;
}