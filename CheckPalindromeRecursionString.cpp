#include <iostream>
using namespace std;

bool palindrome(string s){
    if (s.length()==0) return true;
    else return((s[0]==s[s.size()-1])&&palindrome(s.substr(1,s.size()-2)));
}

int main(){
    string s = "paassdaap";
    cout<<palindrome(s)<<endl;
}