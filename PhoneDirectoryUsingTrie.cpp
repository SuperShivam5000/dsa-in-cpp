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
    void generateQueries(TrieNode* root, vector<string> &currentResult, string temp){
        if(root==NULL) return;
        if(root->isTerminal) currentResult.push_back(temp);
        for(int i=0;i<26;i++){
            if (root->children[i]) {
                char ch='a' + i;
                generateQueries(root->children[i], currentResult, temp+ch);
            }
        }
    }
    void traversal(TrieNode* root, vector<string> &currentResult, string currentQuery, string temp){
        if(root==NULL) return;
        if (currentQuery.empty()) { generateQueries(root, currentResult, temp); return; }

        int index=currentQuery[0]-'a';
        if(root->children[index]) traversal(root->children[index], currentResult, currentQuery.substr(1), temp+currentQuery[0]); 
        else return;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie t;
    for(int i=0;i<contactList.size();i++){
        t.insert(t.root, contactList[i]);
    }

    vector<vector<string>> ans;
    string currentQuery;
    for(int i=0;i<queryStr.size();i++){
        currentQuery+=queryStr[i];
        vector<string> currentResult;
        t.traversal(t.root, currentResult, currentQuery, "");
        if(!currentResult.empty()) ans.push_back(currentResult);
    }
    return ans;
}