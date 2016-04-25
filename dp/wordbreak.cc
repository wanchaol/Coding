#include "../utils.h"

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        
        vector<bool> states(s.size() + 1, false);
        states[0] = true;
        
        for(int i = 1; i <= s.size(); ++ i) {
            for(int j = i-1; j >=0; -- j) {
                if(states[j]) {
                    string sub = s.substr(j, i-j);
                    if(wordDict.count(sub)) {
                        states[i] = true;
                        break;
                    }
                }
                
            }
            
        }
     
        return states[s.size()];
    }

    bool wordBreakBfs(string s, unordered_set<string>& wordDict) {
        
		queue<int> Q;
		unordered_set<int> visited;
		
		Q.push(0);

		while(!Q.empty()) {
			int sind = Q.front();
			Q.pop();

			if (visited.count(sind)) {
				visited.insert(sind);

				for (int i = sind; i < s.size(); ++i) {

                    string sub = s.substr(sind, i - sind + 1);

					if (wordDict.count(sub)) {
						Q.push(i + 1);
						if (i + 1 == s.size()) {
							return true;
						}
						
					}
					
				}


			}

		}
		return false;
     
        
    }
};
