#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

int main(){
    int n;
    cin>>n;

    int i,r,num=0,c=0;
    for(i=n;i>0;i/=10){
        r=i%10;
        num=num+r*pow(8,c);
        c++;
    }
    cout<<num<<endl;
}