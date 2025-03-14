#include <iostream>
using namespace std;

string removeduplicates(string s){
    if(s.size()==0) return "";
    else if(s[0]==s[1]) return removeduplicates(s.substr(1));
    else return s[0] + removeduplicates(s.substr(1));
}

int main(){
    string s = "aaaabbbeeecdddd";
    cout<<removeduplicates(s)<<endl;
}