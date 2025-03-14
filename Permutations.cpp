#include <iostream>
using namespace std;

void permutations(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        string ros = s.substr(0,i)+s.substr(i+1);
        permutations(ros,ans+ch);
    }
}

int main(){
    string s="abcccdde";
    permutations(s,"");
}