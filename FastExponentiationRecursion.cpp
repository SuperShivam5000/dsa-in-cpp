#include <bits/stdc++.h>
using namespace std;

int exp(int a,int b){
    if(b==0) return 1;
    else if(b%2==0) return exp(a,b/2)*exp(a,b/2);
    else return exp(a,b/2)*exp(a,b/2)*a;
}

int main(){
    int a=3;
    int b=5;
    cout<<exp(a,b)<<endl;
}