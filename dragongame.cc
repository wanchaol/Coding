#include "utils.h"

class Solution {
   public:
    string dragongame(vector<int> &nums) {
        string res = "0 ";

        if (nums.size() == 0) return "failure";

        size_t i = 0;
        size_t maxJump = nums[0];

        while (i < nums.size()) {
            if (maxJump >= nums.size() - 1) {
                res += to_string(nums.size() - 1) + " ";
                break;
            }

            size_t subMaxInd = 0;
            size_t subMaxJump = 0;

            for (size_t j = i + 1; j < i + nums[i] && j < nums.size(); j++) {
                if (j + nums[j] > subMaxJump) {
                    subMaxInd = j;
                    subMaxJump = j + nums[j];
                }
            }

            i = subMaxInd;
            maxJump = subMaxJump;

            if (maxJump == 0) return "failure";

            res += to_string(i) + " ";
        }

        return res;
    }

   private:
    /* data */
};

int main(int argc, char *argv[]) {
    Solution sol;
    std::vector<int> v{0, 0, 0};
    cout << sol.dragongame(v);

    return 0;
}
