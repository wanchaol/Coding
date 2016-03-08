#include "utils.h"

class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        
        if(nums.empty())
            return res;
        
        sort(nums.begin(), nums.end());
        
        int size = nums.size();
        for(int i = 0; i < size; ++ i) {
            int target3 = target - nums[i];    
            
            for(int j = i + 1; j < size; j ++) {
                int target2 = target3 - nums[j];
                
                int left = j + 1;
                int right = size-1;
                
                while(left < right) {
                    int twosum = nums[left] + nums[right];
                    
                    if(twosum > target2)
                        right--;
                    else if(twosum < target2)
                        left++;
                    else{
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[left];
                        quadruplet[3] = nums[right];
                        res.push_back(quadruplet);
                    
                        while(left < right && nums[left] == quadruplet[2]) left++;
                        while(left < right && nums[right] == quadruplet[3]) right--;
                    
                        // left++;
                        // right--;
                    }
              
                }
           
                while(j + 1 < size && nums[j + 1] == nums[j]) j++;
            }
            while(i + 1 < size && nums[i + 1] == nums[i]) i++;
        }
        
        return res;
    }
  
};

int main(int argc, char *argv[])
{
	Solution sol;

	vector<int> test{1,2,-3,2,1};
	vector<vector<int>> res = sol.fourSum(test, 1);

	for (auto item : res) {
		cout<<item<<endl;
	}
	
	return 0;
}

