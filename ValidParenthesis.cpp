bool isValidParenthesis(string s)
{
    stack<char> sta;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
            if(sta.empty()) return false;
            if(sta.top()=='(') sta.pop();
            else return false;
        }
        else if(s[i]=='}'){
            if(sta.empty()) return false;
            if(sta.top()=='{') sta.pop();
            else return false;
        }
        else if(s[i]==']'){
            if(sta.empty()) return false;
            if(sta.top()=='[') sta.pop();
            else return false;
        }
        else sta.push(s[i]);
    }
    return true;
}