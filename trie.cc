#include "utils.h"

class TrieNode {
public:
    TrieNode *next[26];
    bool terminates;

    // Initialize your data structure here.
    TrieNode() : next(), terminates(false){
    }
    ~TrieNode() {
        for(int i = 0; i < 26; ++i) {
            delete next[i];
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        
        for(int i = 0; i < word.size(); ++ i) {
            if(p->next[word[i] - 'a'] == nullptr)
                p->next[word[i] - 'a'] = new TrieNode();
            
            p = p->next[word[i] - 'a'];
        }
        
        p->terminates = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = find(word);
        
        return p != nullptr && p->terminates;
        
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = find(prefix);
        
        return p!= nullptr;
    }

private:
    TrieNode* root;
    
    TrieNode* find(string key) {
        TrieNode *p = root;
        
        for(int i = 0; i < key.size(); ++ i) {
            if(p == nullptr)
                return nullptr;
            else
                p = p->next[key[i]-'a'];
        }
        
        return p;
    }
    
    
    
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
