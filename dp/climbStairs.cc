#define CATCH_CONFIG_MAIN
#include "../utils.h"
#include "../catch.hpp"

int climbStairs(int n) {
	if (n == 0) {
		return 1;
	}

	vector<int> states(n + 1, 0);

	states[0] = 1;
	states[1] = 1;

	for (int i = 2; i <= n; ++i) {
		states[i] = states[i-1] + states[i-2];
	}

	return states[n];

}

TEST_CASE("n=1", "[cs]") {
	REQUIRE(climbStairs(1) == 1);
}
