#include "utils.h"

class Solution
{
public:

	bool ifCanWin(string &s) {

		for(size_t i = 0; i < s.size() - 1; ++ i) {
			if (s[i] == '+' && s[i+1] == '+') {
				s[i] = '-';
				s[i + 1] = '-';

				if (!ifCanWin(s)) {
					//if there's any one way the next player can't win, take it and you'll win
					return true;
				}

				s[i] = '+';
				s[i + 1] = '+';

			}        

		}
		return false;

	}

	bool canWin(string s) {
		//int start = 0;
		if (s.size() == 0)
			return false;

		return ifCanWin(s);
	}
private:
	/* data */
};


int main(int argc, char *argv[])
{
	
	return 0;
}
