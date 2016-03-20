#include "utils.h"


class Solution {

private:
	bool IsPal(string s, int left, int right) {
		if(left == right)
			return true;
	
		while(left < right) {
			if(s[left] != s[right])
				return false;
			++left;
			--right;
		}

		return true;
	}


	void backtrack(vector<vector<string>> &res, vector<string> &sol, string &s, int start) {

		if (start == s.size() && sol.size() > 0) {
			res.push_back(sol);
			return;
		}


		for (size_t i = start; i < s.size(); ++i) {
			
			if (IsPal(s, start, i)) {

				sol.push_back(s.substr(start, (i - start) + 1));
				backtrack(res, sol, s, i + 1);
				sol.pop_back();
			}
		}

	}

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
		vector<string> sol;

		backtrack(res, sol, s, 0);
		return res;
    }
};

int main(int argc, char *argv[])
{
	string s = "aab";
	Solution sol;
	vector<vector<string>> res = sol.partition(s);

	for (auto item : res) {
		cout<<item<<endl;
	}
	
	return 0;
}
