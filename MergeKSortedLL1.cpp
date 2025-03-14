/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
Node* merge(Node* a,Node* b){
    Node* temp1=a;
    Node* temp2=b;

    Node* newhead=new Node(-1);
    Node* newtail=newhead;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<temp2->data){
            newtail->next=temp1;
            newtail=newtail->next;
            temp1=temp1->next;
        } 
        else if(temp2->data<temp1->data){
            newtail->next=temp2;
            newtail=newtail->next;
            temp2=temp2->next;
        }
        else {
            newtail->next=temp1;
            newtail=newtail->next;
            temp1=temp1->next;

            newtail->next=temp2;
            newtail=newtail->next;
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        newtail->next=temp1;
        newtail=newtail->next;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        newtail->next=temp2;
        newtail=newtail->next;
        temp2=temp2->next;
    }
    Node* tobedeleted=newhead;
    newhead=newhead->next;
    delete tobedeleted;
    return newhead;

}

Node* mergeKLists(vector<Node*> &listArray){ 
    queue<Node*> q;
    for(int i=0;i<listArray.size();i++) q.push(listArray[i]);
    while(q.size()>1){
        Node* a=q.front();
        q.pop();
        Node* b=q.front();
        q.pop();
        q.push(merge(a,b));
    }
    return q.front();
}
