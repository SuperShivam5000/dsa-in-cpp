#include <bits/stdc++.h>
using namespace std;

int main(){
    int r1,c1;
    cin>>r1;
    cin>>c1;
    int a1[r1][c1];
    int i,j,k;
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            cin>>a1[i][j];
        }
    }

    int r2,c2;
    cin>>r2;
    cin>>c2;
    int a2[r2][c2];
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            cin>>a2[i][j];
        }
    }
    if(r2!=c1) {
        cout<<"Multiplication not possible";
        return 0;
    }

    int result[r1][c2];
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            result[i][j]=0;
            for(k=0;k<r2;k++){
                result[i][j]+=a1[i][k]*a2[k][j];
            }
        }
    }
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}