#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={10,20,30};
    cout<<*arr<<endl; //prints 10
    cout<<*(arr+1)<<endl; //prints 20
    cout<<*(arr+2)<<endl; //prints 30

    int i;
    int *ptr = arr;
    for(i=0;i<3;i++){ // prints whole array
        cout<<*ptr<<" ";
        ptr++;
    }
    return 0;
}