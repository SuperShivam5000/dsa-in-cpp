#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cin>>r;
    cin>>c;
    int arr[r][c];
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    int key;
    cout<<"Enter Key: ";
    cin>>key;

    int s=0,e=c-1,m,col=-1;
    while(s<=e){
        m=(s+e)/2;
        if(arr[0][m] == key){
            cout<<"Found"<<endl;
            return 0;
        }
        else if (m + 1 < c && arr[0][m] < key && arr[0][m+1]>key){
            col=m;
            break;
        }
        else if(arr[0][m]<key){
            s=m+1;
        }
        else{
            e=m-1;
        }
    }
    if(col==-1) col=c-1;
    s=0,e=r-1;
    while(s<=e){
        m=(s+e)/2;
        if (arr[m][col] == key){
            cout<<"Found"<<endl;
            return 0;
        }
        else if(arr[m][col]<key){
            s=m+1;
        }
        else{
            e=m-1;
        }
    }
    cout<<"Not Found"<<endl;
    return 0;
}