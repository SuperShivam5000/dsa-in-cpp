#include <bits/stdc++.h>
using namespace std;

int main(){
    char arr[100]="apple"; //automatically includes null
    
    int i=0;
    while(arr[i]!='\0'){
        cout<<arr[i]<<endl;
        i++;
    }

    char arr2[100];
    cin>>arr2;
    cout<<arr2<<endl;
    cout<<arr2[2]<<endl;
    return 0;
}