#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

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
    //print
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}