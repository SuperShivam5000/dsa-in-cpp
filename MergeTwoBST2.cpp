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

void BSTToDoubleLL(TreeNode* root,TreeNode* &head){
    if(root==NULL) return;

    BSTToDoubleLL(root->right, head);

    root->right=head;
    if(head)head->left=root;
    head=root;

    BSTToDoubleLL(root->left, head);
}

TreeNode* merge(TreeNode* &head1, TreeNode* &head2){
    TreeNode* temp1=head1;
    TreeNode* temp2=head2;

    TreeNode* newhead = new TreeNode(-1);
    TreeNode* newnext = newhead;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<temp2->data){
            newnext->right=temp1;
            temp1->left=newnext;

            newnext=newnext->right;
            temp1=temp1->right;
        } else {
            newnext->right=temp2;
            temp2->left=newnext;

            newnext=newnext->right;
            temp2=temp2->right;
        }
    }
    while(temp1!=NULL){
        newnext->right=temp1;
        temp1->left=newnext;

        newnext=newnext->right;
        temp1=temp1->right;
    }
    while(temp2!=NULL){
        newnext->right=temp2;
        temp2->left=newnext;

        newnext=newnext->right;
        temp2=temp2->right;
    }

    TreeNode* del = newhead;
    newhead=newhead->right;
    newhead->left=NULL;
    delete del;

    return newhead;
}

TreeNode* sortedLLToBST(TreeNode* &head, int n){
    if(n<=0 || head==NULL) return NULL;

    TreeNode* left = sortedLLToBST(head, n/2);

    TreeNode* root = head;
    root->left = left;
    head=head->right;

    root->right = sortedLLToBST(head, n-n/2-1);
    return root;
}

int findsize(TreeNode* &head){
    int x=0;
    TreeNode* temp=head;
    while(temp!=NULL){
        temp=temp->right;
        x++;
    }
    return x;
}

void inorder(TreeNode* head,vector<int> &ans){
    if(head==NULL) return;

    inorder(head->left,ans);
    ans.push_back(head->data);
    inorder(head->right,ans);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2) //use this approach ONLY when size required is O(log(m)+log(n)) instead of O(m+n) and also when return type is not vector(inorder) but root of merged bst.
{
    //convert both BST to Double LLs
    TreeNode* head1=NULL;
    TreeNode* head2=NULL;
    BSTToDoubleLL(root1, head1);
    BSTToDoubleLL(root2, head2);

    //merge both LLs;
    TreeNode* merged = merge(head1, head2);

    //convert merged LL to BST
    TreeNode* final = sortedLLToBST(merged, findsize(merged));

    //return inorder
    vector<int> ans;
    inorder(final,ans);
    return ans;
}