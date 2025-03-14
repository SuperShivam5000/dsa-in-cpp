#include <bits/stdc++.h>
using namespace std;

int main(){
    char arr[]="hadidah"; //automatically includes null
    int n=sizeof(arr);
    int i;
    bool palindrome=true;
    for(i=i;i<n/2;i++){
        if(arr[i]!=arr[n-i-2]) palindrome=false;
    }
    if(palindrome) cout<<"Palindrome"<<endl;
    else cout<<"Not Palindrome"<<endl;
    return 0;
}