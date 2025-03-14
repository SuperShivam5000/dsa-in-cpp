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
    int occurences[max];
    for(i=0;i<max;i++){
        occurences[i]=0;
    }
    for(i=0;i<n;i++){
        occurences[arr[i]]++;
    }
    for(i=0;i<n;i++){
        if (occurences[arr[i]]>=2){
            cout<<occurences[arr[i]]<<endl;
            return 0;
        }
    }
    cout<<"No Repeating Elements"<<endl;
    return 0;
}