#include "utils.h"

class Solution {
private:
    string shift(string &s) {
        int slen = s.size();
        if(slen == 0)
            return nullptr;
        string temp;
        for(int i = 1; i < slen; ++ i) {
            int diff = s[i] - s[i - 1];
            if(diff < 0) diff += 26;
            
            temp += 'a' + diff;
        }
        
        return temp;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        
        for(auto s: strings) {
            map[shift(s)].push_back(s);
        }
        
        for(auto pair: map) {
            vector<string> temp = pair.second;
            sort(temp.begin(), temp.end());
            res.push_back(temp);
        }
        return res;
    }
    
};
