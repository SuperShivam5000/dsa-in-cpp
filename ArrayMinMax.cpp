#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    int min=arr[0], max=arr[0];
    for(i=0;i<n;i++){
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    cout<<"Max: "<<max<<endl;
    cout<<"Min: "<<min<<endl;

    return 0;
}