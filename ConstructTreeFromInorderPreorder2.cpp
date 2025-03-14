//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution { //this is optimal code in o(n*log(n))
  public:
    void buildTree(vector<int> &inorder, map<int,int> &m){
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
    }
    Node *solve(vector<int> &inorder, vector<int> &preorder, map<int,int> &m,int preorderstart,int preorderend,int inorderstart,int inorderend){
        if(preorderstart>preorderend||inorderstart>inorderend) return NULL;
        int root = preorder[preorderstart];
        int index = m[root];
        int size=index-inorderstart;
        Node*temp = new Node(root);
        //preorderstart,preorderend,inorderstart,inorderend
        temp->left = solve(inorder,preorder,m,preorderstart+1,preorderstart+size,inorderstart,index-1);
        temp->right = solve(inorder,preorder,m,preorderstart+size+1,preorderend,index+1,inorderend);
        return temp;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        map<int,int> m;
        buildTree(inorder,m);
        int n=inorder.size();
        return solve(inorder,preorder,m,0,n-1,0,n-1);
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends