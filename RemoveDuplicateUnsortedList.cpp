#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void removeduplicateunsorted(node* &head){
    map<int,int> m;
    node*temp=head;
    m[head->data] = 1;
    while(temp->next != NULL){
        m[temp->next->data]++;
        if(m[temp->next->data]>1){
            //delete the node
            node* tobedeleted=temp->next;
            temp->next=temp->next->next;
            delete tobedeleted;
        }
        else temp=temp->next;
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
    removeduplicateunsorted(head);
    //print
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}