#include "utils.h"

class NumArray {
    // const int N = 1e5;
    vector<int> vals;
    int n;

   public:
    NumArray(vector<int> &nums) : vals(2 * nums.size()) {
        n = nums.size();

        for (int i = n; i < 2 * n; ++i) {
            vals[i] = nums[i - n];
        }
        for (int i = n - 1; i > 0; --i) {
            vals[i] = vals[i << 1] + vals[i << 1 | 1];
        }
    }

    void update(int i, int val) {
        for (vals[i += n] = val; i > 1; i >>= 1) {
            vals[i >> 1] = vals[i] + vals[i ^ 1];
        }
    }

    int sumRange(int i, int j) {
        int res = 0;
        ++j;

        for (i += n, j += n; i < j; i >>= 1, j >>= 1) {
            if (i & 1) {
                res += vals[i++];
            }

            if (j & 1) {
                res += vals[--j];
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums{1, 3, 5};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2) << endl;

    return 0;
}

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
