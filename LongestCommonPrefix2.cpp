class TrieNode{
    public:
    char data;
    bool isTerminal;
    int childCount;
    TrieNode* children[26];
    TrieNode(int d){
        data=d;
        isTerminal=false;
        childCount=0;
        for(int i=0;i<26;i++) children[i]=NULL;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode(-1);
    }
    void insert(TrieNode* root, string word){
        if(root==NULL) return;
        if(word.size()==0) { root->isTerminal=true; return; }
        int index=word[0]-'a';
        if(root->children[index]){
            insert(root->children[index],word.substr(1));
        }
        else{
            root->children[index]=new TrieNode(word[0]);
            root->childCount++;
            insert(root->children[index],word.substr(1));
        }
    }
    void traversal(TrieNode* root, string &ans){
        if(root->childCount==1) {
            for(int i=0;i<26;i++){
                if(root->children[i]!=NULL) {
                    ans.push_back('a'+ i);
                    traversal(root->children[i],ans);
                    break;
                }
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n) //This is Trie based solution but gives TLE. Solution 1 is far more efficient and also easier. This solution also takes a lot more space due to Trie (O(m*n) vs O(m))
{
    Trie t;
    for(int i=0;i<n;i++){
        t.insert(t.root, arr[i]);
    }
    string ans;
    t.traversal(t.root, ans);
    return ans;
}