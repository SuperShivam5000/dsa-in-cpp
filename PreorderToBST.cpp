#include <bits/stdc++.h> 
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/
BinaryTreeNode<int>* solve(vector<int> &preorder,int min,int max,int &i){ //remember to send i by reference!!! you made mistake
    if(i>=preorder.size()) return NULL;
    int ele = preorder[i];
    if(min<ele&&ele<max){
        BinaryTreeNode<int>*temp=new BinaryTreeNode<int>(ele);
        i++;
        temp->left=solve(preorder,min,ele,i);
        temp->right=solve(preorder,ele,max,i);
        return temp;
    }
    else return NULL;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int i=0;
    return solve(preorder,INT_MIN,INT_MAX,i);
}