#include <bits/stdc++.h> 
class Queue {
public:
    int *arr;
    int start;
    int end;
    Queue() {
        arr=new int[10000];
        start=-1;
        end=-1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(start==-1) return true;
        else return false;
    }

    void enqueue(int data) {
        if(start==-1){
            start++;
            end++;
            arr[end]=data;
        }
        else {
            end++;
            arr[end]=data;
        }
    }

    int dequeue() {
        if(isEmpty()) return -1;
        int data=arr[start];
        if(start==end) {
            start=-1;
            end=-1;
        }
        else{
            start++;
        }
        return data;
    }

    int front() {
        if(isEmpty()) return -1;
        return arr[start];
    }
};