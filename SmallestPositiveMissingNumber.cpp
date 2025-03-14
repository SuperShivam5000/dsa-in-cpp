#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int i,max;
    for(i=0;i<n;i++){
        cin>>arr[i];
        if(i==0 || arr[i]>max)max=arr[i];
    }
    max++;
    bool present[max];
    for(i=0;i<max;i++){
        present[i]=false;
    }
    for(i=0;i<n;i++){
        if(arr[i]>=0) present[arr[i]]=true;
    }
    for(i=0;i<max;i++){
        if (!present[i]){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}