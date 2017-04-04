#include "utils.h"

class Solution {
    void backtrack(vector<vector<int>> &res, vector<int> &factors, int n,
                   int start) {
        if (n <= 1) {
            if (factors.size() > 1) res.push_back(factors);
            return;
        }

        for (int i = start; i <= n; ++i) {
            if (n % i == 0) {
                factors.push_back(i);
                backtrack(res, factors, n / i, i);
                factors.pop_back();
            }
        }
    }
    void backtrack2(vector<vector<int>> &res, vector<int> &factors, int n,
                    int start) {
        for (int i = start; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                vector<int> new_facs(factors);
                new_facs.push_back(i);
                backtrack2(res, new_facs, n / i, i);
                new_facs.push_back(n / i);
                res.push_back(new_facs);
            }
        }
    }

   public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;

        vector<int> factors;
        backtrack(res, factors, n, 2);

        return res;
    }
};
