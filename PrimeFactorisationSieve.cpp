#include <iostream>
using namespace std;

int main(){
    int n=1680;
    int spf[n]={0};
    int i,j;
    for(i=2;i<=n;i++){
        spf[i]=i;
    }
    for(i=2;i<=n;i++){
        if(spf[i]==i){
            for(j=i*i;j<=n;j=j+i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
    while(n!=1){
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }
}