#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
};

void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(node* head){
    node* temp=head;
    int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}

void insertAtHead(node* &head,node* &tail,int d){
    node* newnode = new node(d);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}

void insertAtTail(node* &head,node* &tail,int d){
    node* newnode = new node(d);
    if(tail==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    newnode->prev=tail;
    tail->next=newnode;
    tail=newnode;
}

void insertAtPosition(node* &head,node* &tail,int pos,int d){
    if(pos==1){
        insertAtHead(head,tail,d);
        return;
    }
    node* newnode = new node(d);
    node*temp=head;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    if(temp->next==NULL){
        insertAtTail(head,tail,d);
        return;
    }
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
}

void deleteAtPosition(node* &head,node* &tail,int pos){
    if(pos==1){
        node*temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }
    int i=1;
    node*temp=head;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    if(temp->next==NULL){
        tail=temp->prev;
        temp->prev->next=NULL;
        temp->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    temp->next=NULL;
    temp->prev=NULL;
    delete temp;
}

int main(){
    node* head=NULL;
    node* tail=NULL;
    insertAtHead(head,tail,10);
    print(head);
    cout<<"Length: "<<getLength(head)<<endl;
    insertAtHead(head,tail,11);
    insertAtHead(head,tail,12);
    insertAtHead(head,tail,13);
    print(head);
    insertAtTail(head,tail,14);
    insertAtTail(head,tail,15);
    print(head);
    insertAtPosition(head,tail,3,16);
    insertAtPosition(head,tail,1,17);
    insertAtPosition(head,tail,9,18);
    print(head);
    deleteAtPosition(head,tail,1);
    print(head);
    deleteAtPosition(head,tail,3);
    print(head);
    deleteAtPosition(head,tail,7);
    print(head);
}