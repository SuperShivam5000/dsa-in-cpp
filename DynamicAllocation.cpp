#include <iostream>
using namespace std;

int main()
{
    int *ptr = new int; //dynamic memory allocation in heap. new keyword returns address. 12 bytes total used.
    char *ch = new char; //9 bytes total, 8 for address, 1 for char
    *ptr=10;
    *ch='a';
    cout<<*ptr<<*ch<<endl;
    delete ptr; //delete dynamically allocated data


    int *arr = new int[5]; //dynamically allocated array. total used 28 bytes
    delete[]arr; //delete dynamic allocated array
}