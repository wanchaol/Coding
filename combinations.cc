#include "utils.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res; 
  
        vector<int> temp;
        
        backtrack(temp, 1, n, k, res);
        
        return res;      
    }
    
    
    void backtrack(vector<int> &temp, int begin, int n, int k, vector<vector<int>> &res) {
        if(k == 0) {
            res.push_back(temp);
            return;
        }
        
        for(int i = begin; i <= n; ++ i) {
            temp.push_back(i);
            
            //select k-1 numbers starting from the i+1 index of the array(since i is selected!)
            backtrack(temp, i+1, n, k -1, res);
            temp.pop_back();
        }
        
        
    }
};

int main(int argc, char *argv[])
{
	Solution sol;

	vector<vector<int>> res = sol.combine(5, 3);

	for (auto item : res) {
		cout<<item<<endl;
	}
	return 0;
}
