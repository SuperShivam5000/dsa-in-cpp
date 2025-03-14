#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void detectremoveloop(node* &head){
    if(head==NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    if(head->next==head){
        cout<<"Loop Detected! Starting from: "<<head->data<<endl;
        head->next=NULL;
        return;
    }
    map<node*,int> m;
    node* temp=head;
    while(temp->next!=NULL){
        m[temp->next]++;
        if(m[temp->next]>1){
            cout<<"Loop Detected! Starting from: "<<temp->next->data<<endl;
            temp->next=NULL;
            return;
        }
        temp=temp->next;
    }
    cout<<"No loop detected!"<<endl;
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
    temp->next=head->next; //create a loop
    detectremoveloop(head);
    //print
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}