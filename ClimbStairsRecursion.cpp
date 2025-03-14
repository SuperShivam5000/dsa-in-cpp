#include <bits/stdc++.h>
using namespace std;

int climbstairs(int n){
    if(n==1) return 1;
    else if (n==2) return 2;
    else return climbstairs(n-1) + climbstairs(n-2);
}

int main(){
    int n=5;
    cout<<climbstairs(n)<<endl;
}