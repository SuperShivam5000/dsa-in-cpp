#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void inorder(TreeNode<int>* root, TreeNode<int>* &newhead, TreeNode<int>* &temp){
    if(root==NULL) return;

    inorder(root->left,newhead,temp);
    if(newhead==NULL){
        newhead = new TreeNode<int>(root->data);
        temp=newhead;
    }
    else {
        temp->right = new TreeNode<int>(root->data);
        temp=temp->right;
    }
    inorder(root->right,newhead,temp);
}

TreeNode<int>* flatten(TreeNode<int>* root) //when u tried to use vector for this question, 10/11 test cases passed, 1 failed
{
    TreeNode<int>* newhead=NULL;
    TreeNode<int>* temp=NULL;
    inorder(root,newhead,temp);
    return newhead;
}