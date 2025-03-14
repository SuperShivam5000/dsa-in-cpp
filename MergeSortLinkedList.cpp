#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

node* solve(node* first, node* second){

    //if only one element is present in first list
    if(first->next==NULL){
        first->next=second;
        return first;
    }

    node* curr1=first;
    node* curr2=second;
    node* next1=curr1->next;
    node* next2=curr2->next;

    while(next1!=NULL && curr2!=NULL){
        if(curr2->data >= curr1->data && curr2->data<=next1->data){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;

            curr1=curr2;
            curr2=next2;
        } else {
            curr1=curr1->next;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return first;
            }
        }
    }
    return first;
}

node* merge(node* first, node* second)
{
    if(first==NULL) return second;
    if(second==NULL) return first;

     if(first->data<=second->data){
         return solve(first,second);
     }
     else {
         return solve(second,first);
     }
}

node* mergeSort(node*head){
    if(head==NULL || head->next==NULL) return head;
    node*slow=head;
    node*fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    node* head1=head;
    node* head2=slow->next;
    slow->next=NULL;
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    return merge(head1,head2);
}