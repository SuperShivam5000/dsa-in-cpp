#include <iostream>
using namespace std;

int main() {
    int a = 12;
    cout <<"Size of int: "<<sizeof(a)<<endl;

    float b = 12;
    cout <<"Size of float: "<<sizeof(b)<<endl;

    char c = 'c';
    cout <<"Size of char: "<<sizeof(c)<<endl;

    bool d = 0;
    cout <<"Size of bool: "<<sizeof(d)<<endl;

    short int si;
    long int li;
    cout <<"Size of si: "<<sizeof(si)<<endl;
    cout <<"Size of li: "<<sizeof(li)<<endl;
    
    return 0;
}