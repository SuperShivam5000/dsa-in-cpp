#include <bits/stdc++.h>
using namespace std;

void permutations(string x, int n)
{
    if(x.size()==n){
        cout<<x<<endl;
        return;
    }
    for(int i=n;i<x.size();i++){
        swap(x[0],x[i]);
        permutations(x,n+1);
        swap(x[0],x[i]);
    }
}

int main()
{
    string x = "abc";
    permutations(x, 0);
}