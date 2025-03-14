#include <iostream>
using namespace std;

int main(){
    string str;
    string str1(5,'a'); //aaaaa
    string str2="AdiBest"; //space not allowed
    string str3; 
    getline(cin, str3); //space allowed
    cout<<str3;
    return 0;
}