#include <iostream>
using namespace std;

int main(){
    int n,r,i;
    cin>>n;

    int a=0;

    for(i=n;i>0;i/=10){
        r=i%10;
        a=a+r*r*r;
    }
    if(n==a) cout<<"Armstrong";
    else cout<<"Not Armstrong";
}