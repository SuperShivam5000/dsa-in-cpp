/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
class info{
    public:
    int min;
    int max;
    bool isValid;
    int size;
};

info solve(TreeNode* root, int &ans){
    if(root==NULL){
        return {INT_MAX,INT_MIN,true,0};
    }
    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info current;
    current.min = min(root->data,left.min);
    current.max = max(root->data,right.max);
    current.isValid = (left.isValid && right.isValid && left.max < root->data && root->data < right.min);
    current.size = left.size + right.size + 1;

    if(current.isValid) ans = max(ans,current.size);

    return current;
}

int largestBST(TreeNode * root){
    int maxSize = 0;
    solve(root,maxSize);
    return maxSize;
}