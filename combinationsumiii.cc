#include "utils.h"

class Solution {
   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> sol;

        backtrack(k, n, 1, res, sol);

        return res;
    }

    void backtrack(int k, int n, int begin, vector<vector<int>> &res,
                   vector<int> &sol) {
        if (k == 0) {
            if (n == 0) res.push_back(sol);

            return;
        }

        for (int i = begin; i <= 9; ++i) {
            sol.push_back(i);

            backtrack(k - 1, n - i, i + 1, res, sol);

            sol.pop_back();
        }
    }
};
