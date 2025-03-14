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
class Solution { //this is unoptimal code in o(n^2)
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) { 
        if (inorder.empty() || preorder.empty()) {
            return NULL;
        }
        int root = preorder[0];
        vector<int> leftinorder;
        vector<int> rightinorder;
        vector<int> leftpreorder;
        vector<int> rightpreorder;
        int i;
        for(i=0;inorder[i]!=root;i++){
            leftinorder.push_back(inorder[i]);
        }
        i++;
        while(i<inorder.size()){
            rightinorder.push_back(inorder[i]);
            i++;
        }
        i=1;
        while(leftpreorder.size()<leftinorder.size()){
            leftpreorder.push_back(preorder[i]);
            i++;
        }
        while(i<preorder.size()){
            rightpreorder.push_back(preorder[i]);
            i++;
        }
        Node* temp=new Node(root);
        temp->left = buildTree(leftinorder,leftpreorder);
        temp->right = buildTree(rightinorder,rightpreorder);
        return temp;
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