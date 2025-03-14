#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int i,j,k,sum=0;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            for(k=i;k<=j;k++){
                sum=sum+arr[k];
            }
            cout<<sum<<endl;
            sum=0;
        }
    }
}