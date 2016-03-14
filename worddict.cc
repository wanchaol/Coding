#include "utils.h"

class TrieNode {
public:
    TrieNode *next[26];
    bool terminates;
    
    TrieNode(): next(), terminates(false) {};
    ~TrieNode() {
        for(int i = 0; i < 26; ++ i) {
            delete next[i];
        }
    }
    
};


class WordDictionary {
private:
    TrieNode *root;
    
    bool dfs(const char* word, TrieNode *node) {
        TrieNode *run = node;
        
        for(int i = 0; word[i]; ++ i) {
            
            if(run && word[i] != '.') {
                run = run->next[word[i] - 'a'];
            }
            else if(run && word[i] == '.') {
                TrieNode *temp =run; 
                for(int j = 0; j < 26; ++ j) {
					run = temp->next[j];
                    if(dfs(word + i + 1, run))
                        return true;
                }
                
            }
            else 
                break;
        }
        
        return run && run->terminates;
        
    }
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p = root;
        
        for(size_t i = 0; i < word.size(); ++ i) {
            if(p->next[word[i] - 'a'] == nullptr)
                p->next[word[i] - 'a'] = new TrieNode();
            p = p->next[word[i] - 'a'];
            
        }
        p->terminates = true;
        
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        
        return dfs(word.c_str(), root);
            
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
