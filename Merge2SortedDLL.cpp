TreeNode* merge(TreeNode* &head1, TreeNode* &head2){ //This approach is easier and can also be used for single LL. Here right means next and left means prev.
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