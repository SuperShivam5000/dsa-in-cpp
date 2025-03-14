/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d){
        data=d;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie {

public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie(){
        root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
    void insertUtil(TrieNode* root, string word){
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }

        int index=word[0]-'a';
        if(root->children[index]){
            insertUtil(root->children[index], word.substr(1));
        }
        else {
            root->children[index] = new TrieNode(word[0]);
            insertUtil(root->children[index], word.substr(1));
        }
    }
    void insert(string word) {
        insertUtil(root, word);
    }

    /** Returns if the word is in the trie. */
    bool searchUtil(TrieNode* root, string word){
        if(root==NULL) return false;
        if(word.empty()) return root->isTerminal;
        int index=word[0]-'a';
        if(root->children[index]) return searchUtil(root->children[index],word.substr(1));
        else return false;
    }
    bool search(string word) {
        return searchUtil(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWithUtil(TrieNode* root, string word){
        if(root==NULL) return false;
        if(word.empty()) return true;
        int index=word[0]-'a';
        if(root->children[index]) return startsWithUtil(root->children[index],word.substr(1));
        else return false;
    }
    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
};