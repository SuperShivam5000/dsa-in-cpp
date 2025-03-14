#include <iostream>
using namespace std;

int factorial(int n){
    int fact=1,i;
    for(i=1;i<=n;i++) fact*=i;
    return fact;
}

int combination(int n, int r){
    int c = factorial(n)/(factorial(n-r)*factorial(r));
    return c;
}

int main(){
    int n,r;
    cin>>n;
    cin>>r;
    cout<<combination(n,r)<<endl;
}