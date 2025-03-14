#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> stack;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') stack.push(s[i]);
        if(s[i]==')'){
            bool redundant=true;
            while(stack.top()!='('){
                if(stack.top()=='+'||stack.top()=='-'||stack.top()=='*'||stack.top()=='/'){
                    redundant=false;
                    stack.pop();
                }
            }
            stack.pop();
            if(redundant) return true;
        }
    }
    return false;
}
