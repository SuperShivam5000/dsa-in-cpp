#include <bits/stdc++.h> 
void deleteMiddle(stack<int>&inputStack, int N){
   stack<int> temp;
   for(int i=0;i<N/2;i++){
      temp.push(inputStack.top());
      inputStack.pop();
   }
   inputStack.pop();
   while (!temp.empty()){
      inputStack.push(temp.top());
      temp.pop();
   }
}