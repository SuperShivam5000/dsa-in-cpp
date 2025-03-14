#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

Node* insertIntoBST(Node* root,int data){
    if(root==NULL) {
        root = new Node(data);
        return root;
    }
    if(data>root->data){
        root->right = insertIntoBST(root->right,data);
    }
    else {
        root->left = insertIntoBST(root->left,data);
    }
    return root;
}

void levelordertraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }else{
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

int findmin(Node* root){
    if(root->left) findmin(root->left);
    else return root->data;
}

int findmax(Node* root){
    if(root->right) findmax(root->right);
    else return root->data;
}

int main(){
    Node* root=NULL;
    cout<<"Enter data for BST"<<endl;
    takeInput(root);
    cout<<"Printing BST:"<<endl;
    levelordertraversal(root);
    cout<<"Minimum: "<<findmin(root)<<endl;
    cout<<"Maximum: "<<findmax(root)<<endl;
    return 0;
}