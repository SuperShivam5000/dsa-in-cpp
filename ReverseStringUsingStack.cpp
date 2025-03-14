#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="hadichopan";
    stack<char> st;
    for(int i=0;i<s.size();i++){
        st.push(s[i]);
    }
    for(int i=0;i<s.size();i++){
        s[i]=st.top();
        st.pop();
    }
    cout<<"Ans: "<<s;
}