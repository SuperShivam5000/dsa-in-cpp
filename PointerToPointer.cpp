#include <bits/stdc++.h>
using namespace std;

int main(){
    int a=10;
    int *p;
    p=&a;

    cout<<*p<<endl; //value of a=10

    int **q=&p;

    cout<<*q<<endl; //prints value of p=2000(assume)
    cout<<**q<<endl; //prints value of a=10
    return 0;
}