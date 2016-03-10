#include "utils.h"


class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int mindis = INT_MAX;
        int word1ind = -1;
        int word2ind = -1;
        
        for(int i = 0; i < words.size(); ++ i) {
            if(words[i] == word1) {
                word1ind = i;
            }    
            
            if(words[i] == word2) {
                if(word1 == word2)
                    word1ind = word2ind;
                
                word2ind = i;
            }
            
            if(word1ind != -1 && word2ind != -1) {
                mindis = min(mindis, abs(word1ind - word2ind));
            }
        }
        
        return mindis;
    }
};
