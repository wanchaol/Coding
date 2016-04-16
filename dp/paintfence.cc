#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../utils.h"
#include "../catch.hpp"

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

TEST_CASE( "", "[numWays]" ) {



}

