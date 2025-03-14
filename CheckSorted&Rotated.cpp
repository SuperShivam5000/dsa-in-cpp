#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={8,7,9,1,2,3,4,5,6};
    int flips=0;
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]>arr[i+1]){
            flips++;
        }
    }
    if(flips==0||(flips==1&&arr[0]>=arr[arr.size()-1])) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}