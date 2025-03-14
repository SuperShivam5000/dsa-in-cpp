#include <bits/stdc++.h> 
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};
class Deque
{
    
public:
    // Initialize your data structure.
    int size;
    int elements;
    Node* head;
    Node* tail;
    
    Deque(int n)
    {
        size=n;
        elements=0;
        head=NULL;
        tail=NULL;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(elements>=size) return false;
        Node* newnode = new Node(x);
        if(head==NULL&&tail==NULL){
            head=newnode;
            tail=newnode;
        }
        else {
            newnode->prev = tail;
            tail->next=newnode;
            tail=newnode;
        }
        elements++;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if(elements>=size) return false;
        Node* newnode = new Node(x);
        if(head==NULL&&tail==NULL){
            head=newnode;
            tail=newnode;
        }
        else {
            newnode->next = head;
            head->prev=newnode;
            head=newnode;
        }
        elements++;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(head==NULL&&tail==NULL) return -1;
        int data=tail->data;
        if(head==tail){
            delete head;
            head=NULL;
            tail=NULL;
        }
        else {
            Node*temp=tail;
            tail=tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        elements--;
        return data;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(head==NULL&&tail==NULL) return -1;
        int data=head->data;
        if(head==tail){
            delete head;
            head=NULL;
            tail=NULL;
        }
        else {
            Node*temp=head;
            head=head->next;
            head->prev=NULL;
            delete temp;
        }
        elements--;
        return data;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(head==NULL&&tail==NULL) return -1;
        return head->data;
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(head==NULL&&tail==NULL) return -1;
        return tail->data;
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(head==NULL&&tail==NULL) return true;
        else return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if(size==elements) return true;
        else return false;
    }
};