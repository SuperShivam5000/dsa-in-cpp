/*************************************************************

    Following is the Binary Tree node structure:

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

void inorder(TreeNode *root,vector <int> &v){
    if(root==NULL) return;

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2) //space and time complexity O(m+n)
{
    vector<int> v1,v2;
    inorder(root1,v1);
    inorder(root2,v2);
    vector<int> v3;
    int i=0,j=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]==v2[j]){
            v3.push_back(v1[i]);
            v3.push_back(v2[j]);
            i++;
            j++;
        }
        else if(v1[i]<v2[j]){
            v3.push_back(v1[i]);
            i++;
        }
        else {
            v3.push_back(v2[j]);
            j++;
        }
    }
    while(i<v1.size()){
        v3.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        v3.push_back(v2[j]);
        j++;
    }
    return v3;
}