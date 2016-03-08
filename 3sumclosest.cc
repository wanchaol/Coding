#include "utils.h"

class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target) {

		std::vector<int> v(nums.begin(), nums.end());
		sort(v.begin(), v.end());
		int ans = v[0] + v[1] + v[2]; 

		if (nums.size() <= 3) {
			return accumulate(nums.begin(), nums.end(), 0);
		}

			
		int sum = 0;
		for (int i = 0; i < nums.size() - 2; ++i) {

			int j = i + 1;
			int k = nums.size() - 1;


			while(j < k) {
				sum = v[i] + v[j] + v[k];

				if (abs(sum - target) < abs(ans - target)) {
					ans = sum;
					if (ans == target) {
						return ans;
					}
					
				}
				sum > target? k--:j++;


			}

			
		}
		return ans;

	}


private:
	/* data */
};



int main(int argc, char *argv[])
{

	Solution sol;
	std::vector<int> data{1,2,3,4,5};
	cout<<sol.threeSumClosest(data, 8);

	return 0;
}
