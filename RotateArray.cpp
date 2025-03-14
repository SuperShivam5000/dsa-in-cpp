#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={1,7,9,11,12,3,23,88,4};
    int r=3;
    vector<int>temp;
    
    for(int i=arr.size()-r;i<arr.size();i++) temp.push_back(arr[i]);
    for(int i = arr.size()-1;i>=0;i--) arr[i]=arr[i-r];
    for(int i=0;i<temp.size();i++) arr[i]=temp[i];

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
}