/************************************************************
    Following is the Binary Search Tree node structure

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

************************************************************/

TreeNode *LCAinaBST(TreeNode *root, TreeNode *p, TreeNode *q) //can do same thing iteratively to save space
{
    if(root->data < p->data && root->data < q->data) return LCAinaBST(root->right, p, q);
    else if(root->data > p->data && root->data > q->data) return LCAinaBST(root->left, p, q);
    else return root;
}