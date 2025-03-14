#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={0,1,0,3,12,0};
    int i,j=0;
    for(i=0;i<arr.size();i++){
        if(arr[i]!=0) {
            swap(arr[i],arr[j]);
            j++;
        }
    }
    for(i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
}