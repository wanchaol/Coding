#include "utils.h"


class Solution {
public:

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int len = s.size();
        
        for(int i = 1; i <= 3 && i<= len - 3; ++ i) {
            for(int j = i + 1; j <= i + 3 && j <= len - 2; ++ j ) {
                for(int k = j + 1; k <= j + 3 && k <= len - 1; ++ k) {
                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i, j - i);
                    string s3 = s.substr(j, k - j);
					string s4 = s.substr(k);

					if (IsValid(s1) && IsValid(s2) && IsValid(s3) && IsValid(s4)) {
	
						res.push_back(s1 + '.' + s2 + '.' + s3 + '.' + s4);
						
					}
                    
                    
                }
                
                
            }
            
        }

        
		return res;
    }

	bool IsValid(string s) {
		
		if (s.size() == 0 || s.size()>3 || stoi(s) > 255 || (s[0] == '0' && s.size() > 1)) {
			return false;
			
		}
		return true;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;

	string s = "25525511135";

	vector<string> res;
	res = sol.restoreIpAddresses(s);
	
	cout<<res<<endl;
	return 0;
}
