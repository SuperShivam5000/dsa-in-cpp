#include <iostream>
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

void insertNode(node* &head,int val,int d){
    node* newnode = new node(d);
    if(head==NULL){
        head=newnode;
        newnode->next=newnode;
        return;
    }
    node* temp=head;
    while(temp->data!=val){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void deleteNode(node* &head,int val){
    if(head==NULL){
        cout<<"Empty, nothing to delete";
        return;
    }
    if(head==head->next && head->data == val){
        delete head;
        head=NULL;
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* toBeDeleted = temp->next;
    if(toBeDeleted==head) head=head->next;
    temp->next=toBeDeleted->next;
    toBeDeleted->next=NULL;
    delete toBeDeleted;
}
void print(node*head){
    if(head==NULL){
        cout<<"Empty"<<endl;
        return;
    }
    cout<<head->data<<" ";
    node* temp=head->next;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node *head =NULL;
    insertNode(head,-1,5);
    insertNode(head,5,6);
    insertNode(head,6,7);
    insertNode(head,7,8);
    insertNode(head,8,10);
    insertNode(head,8,9);
    print(head);
    deleteNode(head,6);
    deleteNode(head,9);
    deleteNode(head,5);
    print(head);
    deleteNode(head,7);
    deleteNode(head,10);
    deleteNode(head,8);
    print(head);
    insertNode(head,-1,5);
    insertNode(head,5,6);
    insertNode(head,6,7);
    insertNode(head,7,8);
    insertNode(head,8,10);
    insertNode(head,8,9);
    print(head);
    return 0;
}