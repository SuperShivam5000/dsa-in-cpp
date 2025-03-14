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
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

void sort012(node* &head){
    node* h0=NULL;
    node* h1=NULL;
    node* h2=NULL;

    node* t0=NULL;
    node* t1=NULL;
    node* t2=NULL;
    
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            if(h0==NULL) {h0=temp; t0=h0;}
            else {t0->next=temp; t0=t0->next;}
        }
        else if(temp->data==1){
            if(h1==NULL) {h1=temp; t1=h1;}
            else {t1->next=temp; t1=t1->next;}
        }
        else if(temp->data==2){
            if(h2==NULL) {h2=temp; t2=h2;}
            else {t2->next=temp; t2=t2->next;}
        }
        temp=temp->next;
    }
    t0->next=h1;
    t1->next=h2;
    t2->next=NULL;
    head=h0;
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
    sort012(head);
    print(head);
}