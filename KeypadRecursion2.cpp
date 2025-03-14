#include <bits/stdc++.h>
using namespace std;

string keypadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqr", "xywz"};

void keypad(string x, string a, int n,int size)
{
    if(a.size()==size){
        cout<<a<<endl;
        return;
    }
    string p=keypadArr[x[0]-'0'];
    for (int i = 0; i < p.size(); i++)
    {
        a.push_back(p[i]);
        keypad(x.substr(1),a,n+1,size);
        a.pop_back();
    }
}

int main()
{
    string x = "23";
    int size=x.size();
    keypad(x, "", 0,size);
}