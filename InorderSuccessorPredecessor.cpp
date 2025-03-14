/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

void inorder(TreeNode *root, int key,int &pred,int &succ){
    if(root==NULL) return;

    inorder(root->left,key,pred,succ);
    if(pred<root->data && root->data<key) pred=root->data;
    if(key<root->data && root->data<succ) succ=root->data;
    inorder(root->right,key,pred,succ);
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pred=INT_MIN;
    int succ=INT_MAX;
    inorder(root,key,pred,succ);
    if(pred==INT_MIN) pred=-1;
    if(succ==INT_MAX) succ=-1;
    return{pred,succ};
}