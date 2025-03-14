#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;
    s.top(); //peek
    s.push(5);
    s.pop();
    s.empty();
    //we cant do s[0]=1 random access not allowed
    s.size();
}