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
        for(j=i;j<n;j++){
            sum=sum+arr[j];
            if(sum>max) max=sum;
        }
        sum=0;
    }
    cout<<max<<endl;
}