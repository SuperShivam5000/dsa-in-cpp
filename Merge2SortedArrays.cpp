#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a={1,3,5,7,9};
    vector<int> b={2,4,6};
    vector<int> ans;
    int i=0,j=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]<b[j]){
            ans.push_back(a[i]);
            i++;
        }
        else if(b[j]<a[i]){
            ans.push_back(b[j]);
            j++;
        }
        else{
            ans.push_back(a[i]);
            ans.push_back(b[j]);
            i++;
            j++;
        }
    }
    while(i<a.size()){
        ans.push_back(a[i]);
        i++;
    }
    while(j<b.size()){
        ans.push_back(b[j]);
        j++;
    }
    for(i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}