/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/

void inorder(TreeNode<int>* root, vector<int> &v){
    if(root==NULL) return;

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

TreeNode<int>* createBalancedTree(vector<int> v,int s, int e){
    if(s>e) return NULL;

    int mid=s+(e-s)/2;
    TreeNode<int>* temp = new TreeNode<int>(v[mid]);
    temp->left=createBalancedTree(v,s,mid-1);
    temp->right=createBalancedTree(v,mid+1,e);
    return temp;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> v;
    inorder(root,v);
    return createBalancedTree(v,0,v.size()-1);
}
