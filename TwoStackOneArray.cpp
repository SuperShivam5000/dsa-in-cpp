#include <bits/stdc++.h> 
class TwoStack {

public:

    int top1,top2;
    int *arr;
    int s;
    TwoStack(int s) {
        arr = new int[s];
        this->s=s;
        top1=-1;
        top2=s;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top1<top2-1){
            top1++;
            arr[top1]=num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top1<top2-1){
            top2--;
            arr[top2]=num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1==-1) return -1;
        int x=arr[top1];
        top1--;
        return x;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 == s) return -1;
        int x = arr[top2];
        top2++;
        return x;
    }
};
