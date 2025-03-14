#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter data: ";
    int data;
    cin>>data;

    root = new node(data);
    if(data==-1) return NULL;

    cout<<"Going left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Going right of "<<root->data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelordertraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
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

void inordertraversal(node* root){
    if(root==NULL) return;

    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}

void preordertraversal(node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}

void postordertraversal(node* root){
    if(root==NULL) return;

    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
}
void buildfromlevelorder(node* &root){
    queue<node*> q;
    cout<<"Enter root data"<<endl;
    int data;
    cin>>data;
    root = new node(data);    
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left data for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1) {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right data for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1) {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}
int main(){
    node* root=NULL;
    // root = buildTree(root);
    buildfromlevelorder(root);
    cout<<"Level order traversal: "<<endl;
    levelordertraversal(root);
    cout<<"Inorder traversal: "<<endl;
    inordertraversal(root);
    cout<<endl;
    cout<<"Preorder traversal: "<<endl;
    preordertraversal(root);
    cout<<endl;
    cout<<"Postorder traversal: "<<endl;
    postordertraversal(root);
    cout<<endl;
}