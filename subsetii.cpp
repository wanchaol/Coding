#include "utils.h"

class Solution
{
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {

		vector<vector<int>> res(1, vector<int>());

		sort(nums.begin(), nums.end());


		for (size_t i = 0; i < nums.size();) {
			
			size_t count = 0;

			while (i + count < nums.size() && nums[i + count] == nums[i]) {
				count ++;
				
			}

			int sublen = res.size();

			for (int j = 0; j < sublen; ++j) {
				
				vector<int> instance = res[j];

				for (int k = 0; k < count; ++k) {
					instance.push_back(nums[i]);
					res.push_back(instance);
				}


			}

			i+= count;

		}

		return res;

	}

private:
	
};


int main(int argc, char *argv[])
{
	Solution sol;
	vector<int> nums {1,2,2};
	vector<vector<int>> res = sol.subsetsWithDup(nums);

	for (int i = 0; i < res.size(); ++i) {
		cout<<res[i]<<endl;
	}
	
	return 0;
}
