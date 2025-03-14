#include<bits/stdc++.h>
using namespace std;

int fibo(int n, unordered_map<int,int> &memo){
        if(n==0||n==1) return n;
        if(memo.find(n)!=memo.end()) return memo[n];

        memo[n]=fibo(n-1,memo)+fibo(n-2,memo);
        return memo[n];
}

int main() //top-down approach
{
        unordered_map<int,int> memo;
        int n;
        cin>>n;
        cout<<fibo(n,memo);
}