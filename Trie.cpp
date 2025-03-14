#include <bits/stdc++.h>
using namespace std;

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

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root, string word){
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }

        int index=word[0]-'A';
        if(root->children[index]){
            insertUtil(root->children[index], word.substr(1));
        }
        else {
            root->children[index] = new TrieNode(word[0]);
            insertUtil(root->children[index], word.substr(1));
        }
    }
    void insertWord(string word){
        insertUtil(root, word);
    }
    bool searchUtil(TrieNode* root, string word){
        if(root==NULL) return false;
        if(word.empty()) return root->isTerminal;
        int index=word[0]-'A';
        if(root->children[index]) return searchUtil(root->children[index],word.substr(1));
        else return false;
    }
    bool search(string word){
        return searchUtil(root,word);
    }
    void deleteUtil(TrieNode* root, string word){
        if(root==NULL) return;
        if(word.empty()) root->isTerminal=false;
        int index=word[0]-'A';
        if(root->children[index])deleteUtil(root->children[index],word.substr(1));
        else return;
    }
    void deletion(string word){
        deleteUtil(root,word);
    }
};

int main(){
    Trie t;
    t.insertWord("ABCD");
    cout<<t.search("ABCD")<<endl;
    t.deletion("ABCD"); //this version of deletion does NOT delete the data, simply marks isTerminal=false for the last character of word.
    cout<<t.search("ABCD")<<endl;
    return 0;
}