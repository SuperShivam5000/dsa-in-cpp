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

    int givenSum;
    cout<<"Enter Sum: ";
    cin>>givenSum;

    for(i=0;i<n;i++){
        int sum=0;
        for(j=i;j<n;j++){
            sum+=arr[j];
            if(sum>givenSum) break;
            if(sum==givenSum){
                cout<<"Result: "<<i+1<<" "<<j+1<<endl;
                return 0;
            }
        }
    }
    return 0;
}