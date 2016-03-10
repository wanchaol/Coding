#include "utils.h"


class Solution {
private:
    void backtrack(string &comb, string &digits, vector<string> &mappings, size_t begin, vector<string> &res) {
        if(begin == digits.size()) {
            res.push_back(comb);
            return;
        }
        
        for(size_t i = begin; i < digits.size(); ++ i) {
            int num = digits[i] - '0';
            for(size_t j = 0; j < mappings[num].size(); ++ i) {
                comb += mappings[num][j];
                backtrack(comb, digits, mappings, begin + 1, res);
                comb.pop_back();   
            }
            
            
        }
        
    }
    
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0)
            return res;
        
        vector<string> mappings {"_", "o_o", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        
        string comb;
        
        backtrack(comb, digits, mappings, 0, res);
        
        return res;
        
    }
};

int main(int argc, char *argv[])
{
	Solution sol;

	string s= "2";
	
	cout<< sol.letterCombinations(s);
	return 0;
}
