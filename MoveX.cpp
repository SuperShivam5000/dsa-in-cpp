#include <iostream>
using namespace std;

string movex(string s){
    if(s.length()==0) return "";
    else if(s[0]=='x') return movex(s.substr(1)) + 'x';
    else return s[0]+movex(s.substr(1));
}

int main(){
    string s="dsfcxxgsdfdxsdgfxxfdxxxfsadxfa";
    cout<<movex(s)<<endl;
}