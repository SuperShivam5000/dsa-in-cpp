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

    for(int i=1;i<n;i++){
        int current = arr[i];
        int j=i-1;
        while(arr[j]<current && j>=0){
            arr[j+1]=arr[j];//move forward one position
            j--;
        }
        arr[j+1]=current;
    }
    

    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<endl;
    }
}