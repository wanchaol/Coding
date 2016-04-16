#include "../utils.h"

class Solution
{
public:
	int rob(vector<int> &nums) {
		int prevno = 0;
		int prevyes = 0;

		for (auto num : nums) {
			 int temp = prevno;
			 prevno = max(prevno, prevyes);
			 prevyes = num + temp;
		}

		return max(prevno, prevyes);

	}
private:
	/* data */
};
