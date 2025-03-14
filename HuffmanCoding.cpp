//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
class compare{
    public:
    bool operator()(Node* a,Node* b){
	    return a->data > b->data;
	}
};
class Solution
{
	public:
	void traverse(Node* root, vector<string> &answer, string temp){
	    if(root->left==NULL&&root->right==NULL){
	        answer.push_back(temp);
	        return;
	    }
	    traverse(root->left,answer,temp+"0");
	    traverse(root->right,answer,temp+"1");
	}
	vector<string> huffmanCodes(string S,vector<int> f,int N)
	{
	    priority_queue<Node*, vector<Node*>, compare> h;
	    for(int i=0;i<f.size();i++){
	        Node* newnode = new Node(f[i]);
	        h.push(newnode);
	    }
	    while(h.size()>1){
	        Node* a=h.top();
	        h.pop();
	        Node* b=h.top();
	        h.pop();
	        Node* c= new Node(a->data+b->data);
	        c->left=a;
	        c->right=b;
	        h.push(c);
	    }
	    Node* root=h.top();
	    vector<string> answer;
	    traverse(root,answer,"");
	    return answer;
	}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends