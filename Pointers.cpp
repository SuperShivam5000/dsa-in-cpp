#include <bits/stdc++.h>
using namespace std;

int main(){
    int a=10;
    int *aptr;
    aptr=&a;

    cout<<&a<<endl; //prints address of a
    cout<<aptr<<endl; //prints address of a
    cout <<*aptr<<endl; //prints value of a(also called derefering)
    return 0;
}