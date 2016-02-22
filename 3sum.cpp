#include "utils.h"

class Solution
{
public:
	vector<vector<int>> threesum(vector<int> &nums) {
		 vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        int size = nums.size();
        for(int i = 0; i < size-2 ; ++ i) {
            
            if(i == 0 || (i >0 && nums[i] != nums[i-1])) {
                int left = i + 1;
                int right = size - 1;
                int sum = 0-nums[i];
                
                while(left < right) {
                    
                    if(nums[left] + nums[right] == sum) {
                        res.push_back(vector<int> {nums[i], nums[left], nums[right]});
                        while(left < right && nums[left + 1] == nums[left])left ++;
                        while(right > left && nums[right - 1] == nums[right])right --;
                        
                        left ++;
                        right --;
                        
                    }
                    else if(nums[left] + nums[right] > sum) {
                        right --;
                    }
                    else 
                        left ++;
                    
                }
       
            }

        }
        return res;
	
	}

private:
	/* data */
};


int main(int argc, char *argv[])
{
	Solution sol;

	vector<int> test{1,2,-3,2,1};
	vector<vector<int>> res = sol.threesum(test);

	for (auto item : res) {
		cout<<item<<endl;
	}
	
	return 0;
}

