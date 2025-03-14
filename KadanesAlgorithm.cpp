#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int i,j;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    int max=arr[0],sum=0;
    for(i=0;i<n;i++){
        sum=sum+arr[i];
        if(sum<0) sum=0;
        if(sum>max) max=sum;
    }
    cout<<max<<endl;
}