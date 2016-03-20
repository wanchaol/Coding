#include "utils.h"

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
       unordered_map<int, int> map;
       int sum = 0;
       int maxlen = 0;
       
       for(int i = 0; i < nums.size(); ++ i) {
           sum += nums[i];
           if(sum == k) {
               maxlen = max(maxlen, i + 1);
           }
           
           if(map[sum - k]) {
               maxlen = max(maxlen, i + 1 - map[sum - k]);
           }
           
           if(!map[sum]) {
               map[sum] = i + 1;
           }
       }
       
        return maxlen;    
        
    }
};
