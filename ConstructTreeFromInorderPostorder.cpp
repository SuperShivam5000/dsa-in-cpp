//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution { // o(n*log(n)) optimal time complexity
  public:
    void buildMap(vector<int> &inorder, map<int,int> &m){
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
    }
    Node* solve(vector<int> &inorder, vector<int> &postorder,map<int,int> &m,int inorderstart,int inorderend,int postorderstart,int postorderend){
        if(inorderstart>inorderend||postorderstart>postorderend) return NULL;
        int root = postorder[postorderend];
        int index = m[root];
        Node*temp = new Node(root);
        int size = abs(index-inorderend);
        //inorderstart,inorderend,postorderstart,postorderend
        temp->left =  solve(inorder,postorder,m,inorderstart,index-1,postorderstart,postorderend-size-1);
        temp->right = solve(inorder,postorder,m,index+1,inorderend,postorderend-size,postorderend-1);
        return temp;
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        map<int,int> m;
        buildMap(inorder,m);
        int n = inorder.size();
        return solve(inorder,postorder,m,0,n-1,0,n-1);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> inorder;
        int number;
        while (ss >> number) {
            inorder.push_back(number);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> postorder;
        while (ss2 >> number) {
            postorder.push_back(number);
        }
        Solution obj;
        Node* root = obj.buildTree(inorder, postorder);
        preOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends