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
class comparator{
    public:
    bool operator()(Node* n1, Node* n2){
        return n1->data>n2->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<Node*,vector<Node*>,comparator> p;
    Node* newhead = new Node(-1);
    Node* newtail = newhead;

    //push all heads
    for(int i=0;i<listArray.size();i++){
        p.push(listArray[i]);
    }
    //main part
    while(!p.empty()){
        Node* top = p.top();
        p.pop();
        newtail->next=top;
        newtail=newtail->next;
        if(top->next) {
            p.push(top->next);
        }
    }
    Node* tobedeleted=newhead;
    newhead=newhead->next;
    delete tobedeleted;
    return newhead;
}
