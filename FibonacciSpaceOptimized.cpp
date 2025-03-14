#include<bits/stdc++.h>
using namespace std;

int main() //basically normal fibonacci, good because less extra space used
{
        int n;
        cin>>n;
        int a=0;
        int b=1;
        int c;
        for(int i=2;i<=n;i++){
                c=a+b;
                a=b;
                b=c;
        }
        if(n<=1) cout<<n;
        else cout<<c;
}