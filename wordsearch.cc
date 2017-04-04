#include "utils.h"
class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (backtrack(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, int i, int j,
                   int start) {
        if (start == word.size()) return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;

        char c = board[i][j];
        if (board[i][j] == word[start]) {
            board[i][j] = '*';

            vector<pair<int, int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

            for (auto dir : dirs) {
                if (backtrack(board, word, i + dir.first, j + dir.second,
                              start + 1))
                    return true;
            }

            board[i][j] = c;
        }

        return false;
    }
};
