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

pair<int, int> predecessorSuccessor(TreeNode *root, int key) //this approach is from lovebabbar but any approach is same
{
    int pred=-1;
    int succ=-1;

    TreeNode* temp=root;
    while(temp){
        if(temp->data == key) {
            break;
        } else if(key<temp->data) {
            succ=temp->data;
            temp=temp->left;
        } else {
            pred=temp->data;
            temp=temp->right;
        }
    }

    if (!temp) {
        return {pred, succ};
    }

    TreeNode* leftTree=temp->left;
    while(leftTree){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }

    TreeNode* rightTree=temp->right;
    while(rightTree){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }

    return {pred,succ};
}