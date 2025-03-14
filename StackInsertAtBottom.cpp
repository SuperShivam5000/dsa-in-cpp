#include <bits/stdc++.h> 
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    stack<int> temp;
    while(!myStack.empty()){
        temp.push(myStack.top());
        myStack.pop();
    }
    myStack.push(x);
    while(!temp.empty()){
        myStack.push(temp.top());
        temp.pop();
    }
    return myStack;
}
