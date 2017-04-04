#include "utils.h"

class Solution {
   public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;

        permuteRecursive(nums, 0, res);

        return res;
    }

    void permuteRecursive(vector<int> &nums, size_t begin,
                          vector<vector<int>> &res) {
        if (begin >= nums.size()) {
            res.push_back(nums);
            return;
        }

        for (size_t i = begin; i < nums.size(); ++i) {
            swap(nums[begin], nums[i]);

            permuteRecursive(nums, begin + 1, res);

            swap(nums[begin], nums[i]);
        }
    }

   private:
    /* data */
};

int main(int argc, char *argv[]) {
    vector<int> nums{1, 2, 3, 4};
    Solution sol;

    vector<vector<int>> res = sol.permute(nums);

    for (auto e : res) {
        cout << e << endl;
    }

    return 0;
}
