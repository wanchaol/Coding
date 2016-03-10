#include "utils.h"


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> res;
        vector<int> sol;
        
        backtrack(0, candidates, sol, target, res);
        
        return res;
        
    }
    
    void backtrack(int begin, vector<int> &nums, vector<int> &sol, int target, vector<vector<int>> &res) {
        
        if(target <= 0 || begin >= nums.size()) {
            if(target == 0) {
                res.push_back(sol);
            }
            return;
        }
        
        for(int i = begin; i < nums.size(); ++ i) {
            
            target -= nums[i];
            sol.push_back(nums[i]);
            
            backtrack(i, nums, sol, target, res);
            
            sol.pop_back();
            target += nums[i];
        }
        
    }
    
    
};

