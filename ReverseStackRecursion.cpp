void pushAtBottom(stack<int>& myStack, int x) 
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
}

void reverseStack(stack<int> &stack) {
    if(!stack.empty()){
        int num=stack.top();
        stack.pop();
        reverseStack(stack);
        pushAtBottom(stack,num);
    }
    else return;
}