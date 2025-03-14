#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int solve(BinaryTreeNode<int>* root, int &i, int k){
    if(root==NULL) return -1;
    //l
    int left = solve(root->left,i,k);
    if(left!=-1) return left;
    //n
    i++;
    if(i==k) return root->data;
    //r
    int right = solve(root->right,i,k);
    if(right!=-1)return right;
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i=0;
    return solve(root,i,k);
}