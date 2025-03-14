#include <bits/stdc++.h> 
void insertSorted(stack<int>& myStack, int x) 
{
    stack<int> temp;
    while(!myStack.empty() && myStack.top() > x){
        temp.push(myStack.top());
        myStack.pop();
    }
    myStack.push(x);
    while(!temp.empty()){
        myStack.push(temp.top());
        temp.pop();
    }
}

void sortStack(stack<int> &stack) {
    if(stack.empty()) return;
    int num=stack.top();
    stack.pop();
    sortStack(stack);
    insertSorted(stack,num);
}