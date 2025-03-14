#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

node* floydcycledetection(node* &head){
    if(head==NULL){
        cout<<"Empty list"<<endl;
        return NULL;
    }
    node* slow=head;
    node* fast=head;
    while(slow!=NULL&&fast!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast==NULL) break;
        fast=fast->next;
        if(fast==slow) {
            cout<<"Loop Detected!"<<endl;
            slow=head;
            while(slow!=NULL&&fast!=NULL){
                slow=slow->next;
                fast=fast->next;
                if(fast==slow) {
                    return fast;
                }
            }
        }
    }
    cout<<"Loop Not Detected!"<<endl;
    return NULL;
}

void floydcycleremoval(node* &head){
    node* start=floydcycledetection(head);
    node* temp=start;
    while(temp->next!=NULL){
        if(temp->next==start){
            temp->next=NULL;
            return;
        }
        temp=temp->next;
    }
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
    floydcycleremoval(head);
    //print
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}