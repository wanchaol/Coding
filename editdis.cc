#include "utils.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> states(m + 1, vector<int> (n + 1, 0));
        
        for(int i = 0; i <= m ; ++ i)
            states[i][0] = i;
        for(int i = 0; i <= n ; ++ i)
            states[0][i] = i;
        
        for(int i = 1; i <= m; ++ i) {
            for(int j = 1; j <= n; ++ j) {
                
                states[i][j] = min(1 + states[i - 1][j], 1 + states[i][j - 1]);
                states[i][j] = min(states[i][j], ((word1[i-1] == word2[j-1]? 0: 1) + states[i-1][j-1]));
                
            }
        }
        
        return states[m][n];
    }
};
