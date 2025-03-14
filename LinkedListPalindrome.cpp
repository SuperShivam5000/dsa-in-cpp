#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void print(node* &head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

void reverse(node* &head){
    node*prev=NULL;
    node*curr=head;
    node*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

bool isPalindrome(node* &head){
    node* slow=head;
    node* fast=head;

    while(slow!=NULL&&fast!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast==NULL) break;
        fast=fast->next;
    }
    reverse(slow);
    node*temp1=head;
    node*temp2=slow;
    while(temp2!=NULL){
        if(temp1->data!=temp2->data) return false;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    //input
    node *head=NULL;
    node *temp=NULL;
    for(int i=0;i<n;i++){
        node *newnode=new node();
        cout<<"Enter element: ";
        cin>>newnode->data;
        if(head==NULL){
            head=newnode;
            temp=head;
        }
        else {
            temp->next=newnode;
            temp=temp->next;
        }
    }

    if(isPalindrome(head))cout<<"Palindrome"<<endl;
    else cout<<"Not Palindrome"<<endl;
}