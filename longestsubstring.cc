#include "utils.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

		if (s.size() <= 1) {
			return s.size();
		}

		unordered_map<char, int> m;
		int maxlen = 0;
		int lastind = 0;

		for (int i = 0; i < s.size(); ++i) {
			
			if (m[s[i]]){
				lastind = max(lastind, m[s[i]]);
			}
			m[s[i]] = i + 1;
			maxlen = max(maxlen, i - lastind + 1);

		}

		return maxlen;
        
    }

};

int main(int argc, char *argv[])
{

	Solution sol;
	string s = "abcacdb";
	cout<<sol.lengthOfLongestSubstring(s) <<endl;
	cout<<sol.test(s);

	
	return 0;
}
