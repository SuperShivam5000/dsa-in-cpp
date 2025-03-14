#include <iostream>
using namespace std;

string removeduplicates(string s){
    if(s.size()==0) return "";
    else if(s[0]=='p'&&s[1]=='i') return "3.14"+removeduplicates(s.substr(2));
    else return s[0] + removeduplicates(s.substr(1));
}

int main(){
    string s = "pippxxppiixipi";
    cout<<removeduplicates(s)<<endl;
}