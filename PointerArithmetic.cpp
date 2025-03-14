#include <bits/stdc++.h>
using namespace std;

int main(){
    int a=10;
    int *aptr=&a;
    cout<<aptr<<endl; //lets say 2000

    aptr++;
    cout<<aptr<<endl; //will be 2004 as size of int is 4 bytes

    return 0;
}