#include "../utils.h"

class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> states(m, vector<int>(n, 1));

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                states[i][j] = states[i - 1][j] + states[i][j - 1];
            }
        }

        return states[m - 1][n - 1];
    }
};
