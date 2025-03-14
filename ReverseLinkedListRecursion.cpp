#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

void reverse(node*&curr,node*prev=NULL,node*next=NULL){
    if (curr==NULL) {
        curr=prev;
        return;
    }
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
    reverse(curr,prev,next);
}

node* reverse2(node*head){ //alternate approach
if(head==NULL || head->next==NULL) return head;
    node* rest = reverse2(head->next);
    head->next->next=head;
    head->next=NULL;
    return rest;
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
    print(head);
    reverse(head);
    print(head);
    head = reverse2(head);
    print(head);
}