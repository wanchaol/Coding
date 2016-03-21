#include "utils.h"

class Solution {
	public:
		int numWays(int n, int k) {
			if(n == 0)
				return 0;
			else if(n == 1)
				return k;

			int same = k;
			int dif = k*(k-1);

			for(int i = 3; i <= n; ++ i) {

				int temp = same;
				same = dif;
				dif = temp *(k-1) + dif *(k-1);

			}

			return same + dif;
		}
};

int main(int argc, char *argv[])
{
	Solution sol;
	cout<< sol.numWays(10, 5) << endl;

	return 0;
}
