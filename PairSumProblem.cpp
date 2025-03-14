#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int i,sum;
    cin>>sum;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int s=0,e=n-1;
    while(s<e){
        int currsum = arr[s]+arr[e];
        if(currsum==sum){
            cout<<s<<" "<<e<<endl;
            return 0;
        }
        else if(currsum<sum) s++;
        else e--;
    }    
    cout<<"No Such Pairs"<<endl;
    return 0;
}