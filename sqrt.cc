#include "utils.h"

class Solution
{
public:
	int sqrt(int x) {

		int r = x;

		while(r * r > x){
			r = (r + x/r)/2;
		}

		return r;

	}

private:
	
};

int main(int argc, char *argv[])
{
	Solution sol;
	cout<<sol.sqrt(50);
	return 0;
}
