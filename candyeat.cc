#include "utils.h"

class Solution {
   public:
    int EatCandies(vector<int> &A, int k) {
        priority_queue<int> q;
        int sum = 0;

        for (auto item : A) {
            q.push(item);
        }

        for (int i = 0; i < k; ++i) {
            int maxitem = q.top();
            q.pop();

            sum += maxitem;
            q.push(maxitem / 2);
        }

        return sum;
    }

   private:
    /* data */
};
