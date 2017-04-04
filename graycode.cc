#include "utils.h"

class Solution {
   public:
    vector<int> grayCode(int n) {
        vector<int> res{0};

        int temp = 0;
        // first iteration
        for (int i = 0; i < n; ++i) {
            temp = 1 << i;

            for (ssize_t j = res.size() - 1; j >= 0; --j) {
                res.push_back(temp | res[j]);
            }
        }

        return res;
    }

   private:
    /* data */
};

int main(int argc, char *argv[]) {
    Solution sol;

    cout << sol.grayCode(4);

    return 0;
}
