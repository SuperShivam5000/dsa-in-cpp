#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

int main(){
    int n;
    cin>>n;

    string num;
    while(n>0){
        if(n%16<=9) num=to_string(n%16)+num;
        else {
            char c=n%16-10+'A';
            num=c+num;
        }
        n=n/16;
    }
    cout<<num<<endl;
}