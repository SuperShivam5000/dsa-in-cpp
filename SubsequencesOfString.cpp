#include <bits/stdc++.h>
using namespace std;



void subsequences(string x,string a,int n){
    if(x.size()==n)
    {
        cout<<a<<endl;
        return;
    }
    subsequences(x,a,n+1);
    a.push_back(x[n]);
    subsequences(x,a,n+1);
}

int main(){
    string x="Hadi";
    subsequences(x,"",0);
}