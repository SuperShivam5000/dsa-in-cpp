#include <iostream>
using namespace std;

void permutations(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    permutations(s.substr(1),ans);
    permutations(s.substr(1),ans+s[0]);
}

int main(){
    string s="abc";
    permutations(s,"");
}