//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void buildParentTree(Node* &root, map<Node*,Node*> &parent, int &target, Node* &targetnode){
        if(root->data==target) targetnode = root;
        
        Node* left=root->left;
        Node* right=root->right;
        
        if(left) parent[left]=root;
        if(right) parent[right]=root;
        
        if(left) buildParentTree(left,parent,target,targetnode);
        if(right) buildParentTree(right,parent,target,targetnode);
    }
    int minTime(Node* root, int target) {
        map<Node*,Node*> parent;
        Node* targetnode=NULL;
        
        buildParentTree(root,parent,target,targetnode);
        
        map<Node*,bool> visited;
        queue<Node*> q;
        
        q.push(targetnode);
        visited[targetnode] = true;
        
        int c=0;
        while(!q.empty()){
            int size=q.size();
            bool burned = false;
            for(int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();
                
                Node* left = front->left;
                Node* right = front->right;
                Node* par = parent[front];
                
                if(left && !visited[left]){
                    visited[left]=true;
                    q.push(left);
                    burned=true;
                }
                if(right && !visited[right]){
                    visited[right]=true;
                    q.push(right);
                    burned=true;
                }
                if(par && !visited[par]){
                    visited[par]=true;
                    q.push(par);
                    burned=true;
                }
            }
            if(burned) c++;
        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends