/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
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
    };
    
***********************************************************/

void solve(BinaryTreeNode<int> *root, int &n){
    if(root==NULL) return;
    solve(root->left,n);
    if(root->left==NULL&&root->right==NULL) n++;
    solve(root->right,n);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int n=0;
    solve(root,n);
    return n;
}