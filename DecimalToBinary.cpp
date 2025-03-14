#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

int main(){
    int n;
    cin>>n;

    string num;
    while(n>0){
        num=to_string(n%2)+num;
        n=n/2;
    }
    cout<<num<<endl;
}