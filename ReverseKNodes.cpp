#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void reverseKNodes(node*&head,int k){
    if(head==NULL)return;
    node*temp=head;
    for(int i=0;i<k-1;i++){
        if(temp->next==NULL) break;
        temp=temp->next;
    }
    node*part1=head;
    node*part2=temp->next;
    temp->next=NULL;
    //reverse
    node*prev=NULL;
    node*curr=head;
    node*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    reverseKNodes(part2,k);
    head->next=part2;
    head=prev;
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

    reverseKNodes(head,3);
    cout<<"ANSWER:-"<<endl;
    print(head);
}