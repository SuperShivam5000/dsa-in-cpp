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
    int n;
    cin>>n;

    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            cout<<combination(i,j)<<" "; //term(i,j) = combination(i,j)
        }
        cout<<endl;
    }
}