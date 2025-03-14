class Solution {
  public:
    Node *copyList(Node *head) {
        map<Node*,Node*> m;
        Node* temp=head;
        Node* anshead=new Node(-1);
        Node* ans=anshead;
        while(temp!=NULL){
            Node* newnode = new Node(temp->data);
            m[temp]=newnode;
            ans->next=newnode;
            ans=ans->next;
            temp=temp->next;
        }
        Node*tobedeleted = anshead;
        anshead=anshead->next;
        delete tobedeleted;
        
        Node*temp1=head;
        Node*temp2=anshead;
        while(temp1!=NULL && temp2!=NULL){
            temp2->random=m[temp1->random];
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return anshead;
    }
};