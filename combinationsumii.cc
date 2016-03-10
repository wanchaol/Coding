#include "utils.h"
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            
            //check for duplicates
            if(i > 0 && nums[i] == nums[i-1] & i > begin) 
              continue;
            
            sol.push_back(nums[i]);
            
            backtrack(i + 1, nums, sol, target - nums[i], res);
            
            sol.pop_back();
        
        }
        
    }

};
