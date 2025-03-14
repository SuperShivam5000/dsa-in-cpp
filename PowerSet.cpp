#include <bits/stdc++.h>
using namespace std;

void printarr(vector<int> res){
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

void powerset(vector<int> arr,vector<int> res,int n){
    if(n>=arr.size()) {
        printarr(res);
        return;
    }
    powerset(arr,res,n+1);
    res.push_back(arr[n]);
    powerset(arr,res,n+1);
}

int main(){
    vector<int> arr={1,2,3};
    powerset(arr,{},0);
}