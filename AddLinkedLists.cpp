#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        this->next=NULL;
    }
};

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

node* addTwoLists(node* h1, node* h2){
    reverse(h1);
    reverse(h2);
    node*t1=h1;
    node*t2=h2;
    node*ans=new node(-1);
    node*anshead=ans;
    int carry=0;
    while(t1!=NULL && t2!=NULL){
        int x=t1->data+t2->data+carry;
        int sum=x%10;
        carry=x/10;
        node*newnode=new node(sum);
        ans->next=newnode;
        ans=ans->next;
        t1=t1->next;
        t2=t2->next;
    }
    while(t1!=NULL){
        int x=t1->data+carry;
        int sum=x%10;
        carry=x/10;
        node*newnode=new node(sum);
        ans->next=newnode;
        ans=ans->next;
        t1=t1->next;
    }
    while(t2!=NULL){
        int x=t2->data+carry;
        int sum=x%10;
        carry=x/10;
        node*newnode=new node(sum);
        ans->next=newnode;
        ans=ans->next;
        t2=t2->next;
    }
    if(carry>0){
        node*newnode=new node(carry);
        ans->next=newnode;
        ans=ans->next;
    }
    node*tobedeleted=anshead;
    anshead=anshead->next;
    delete tobedeleted;
    reverse(anshead);
    return anshead;
}

int main(){
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    //input
    node *head=NULL;
    node *temp=NULL;
    for(int i=0;i<n;i++){
        cout<<"Enter element: ";
        int d;
        cin>>d;
        node *newnode=new node(d);
        if(head==NULL){
            head=newnode;
            temp=head;
        }
        else {
            temp->next=newnode;
            temp=temp->next;
        }
    }
}