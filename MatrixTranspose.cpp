#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n][n];
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    int transpose[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            transpose[j][i]=a[i][j];
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
}