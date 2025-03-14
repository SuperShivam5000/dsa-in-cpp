#include<bits/stdc++.h>
using namespace std;

int main() //bottom-up approach
{
        int n;
        cin>>n;
        vector<int> temp(n+1);
        temp[0]=0;
        temp[1]=1;
        for(int i=2;i<=n;i++){
                temp[i]=temp[i-1]+temp[i-2];
        }
        cout<<temp[n];
}