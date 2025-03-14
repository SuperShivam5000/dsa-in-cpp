#include <bits/stdc++.h>
using namespace std;

class stack{
    private:
    int top=-1;
    int arr[100];
    public:
    void push(int n){
        if(top==99) {
            cout<<"Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=n;
    }
    int pop(){
        if(top==-1) {
            cout<<"Underflow"<<endl;
            return -1;
        }
        int x=arr[top];
        top--;
        return x;
    }
    int peek(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool empty(){
        if(top==-1) return true;
        else return false;
    }
};