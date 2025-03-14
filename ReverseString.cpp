#include <iostream>
using namespace std;

string reverse(string s){
    if (s.length()==0) return "";
    else return reverse(s.substr(1))+s[0];
}

int main(){
    string s = "hadi";
    cout<<reverse(s)<<endl;
}