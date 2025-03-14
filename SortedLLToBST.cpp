TreeNode<int>* sortedLLToBST(TreeNode<int>* &head, int n){
    if (n <= 0 || head == NULL) return NULL;

    TreeNode<int>* left = sortedLLToBST(head, n/2);

    TreeNode<int>* root = head;
    root->left=left;
    head=head->right;

    root->right= sortedLLToBST(head, n-n/2-1);
    return root;
}