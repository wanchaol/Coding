#include "utils.h"

class TrieNode {
   public:
    TrieNode *next[26];
    bool terminates;

    // Initialize your data structure here.
    TrieNode() : next(), terminates(false) {}
    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            delete next[i];
        }
    }
};

class Trie {
   public:
    Trie() { root = new TrieNode(); }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;

        for (int i = 0; i < word.size(); ++i) {
            if (p->next[word[i] - 'a'] == nullptr)
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

        return p != nullptr;
    }

   private:
    TrieNode *root;

    TrieNode *find(string key) {
        TrieNode *p = root;

        for (int i = 0; i < key.size(); ++i) {
            if (p == nullptr)
                return nullptr;
            else
                p = p->next[key[i] - 'a'];
        }

        return p;
    }
};

class Solution {
    Trie trie;

    void backtrack(vector<vector<char>> &board, string word, int i, int j,
                   set<string> &res) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;

        char c = board[i][j];

        if (c == '*') return;

        word += c;

        if (!trie.startsWith(word)) return;

        if (trie.search(word)) {
            res.insert(word);
        }

        board[i][j] = '*';

        vector<pair<int, int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (auto dir : dirs) {
            backtrack(board, word, i + dir.first, j + dir.second, res);
        }

        board[i][j] = c;
    }

   public:
    vector<string> findWords(vector<vector<char>> &board,
                             vector<string> &words) {
        set<string> nodup;

        for (auto word : words) {
            trie.insert(word);
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                backtrack(board, "", i, j, nodup);
            }
        }

        vector<string> res(nodup.begin(), nodup.end());

        return res;
    }
};
