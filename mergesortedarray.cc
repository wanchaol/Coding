#include "utils.h"

class Solution {
   public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0) nums1[k--] = nums2[j--];
    }

    vector<int> mergesortedarray(vector<int> &l1, vector<int> &l2) {
        vector<int> res;

        size_t i = 0;
        size_t j = 0;

        while (i < l1.size() && j < l2.size()) {
            if (l1[i] < l2[j]) {
                res.push_back(l1[i]);
                ++i;

            } else if (l1[i] == l2[j]) {
                res.push_back(l1[i]);
                res.push_back(l2[j]);

                ++i;
                ++j;
            } else {
                res.push_back(l2[j]);
                ++j;
            }
        }

        while (i < l1.size()) {
            res.push_back(l1[i]);
            ++i;
        }
        while (j < l2.size()) {
            res.push_back(l2[j]);
            ++j;
        }

        return res;
    }

   private:
    /* data */
};

int main(int argc, char *argv[]) {
    Solution sol;
    vector<int> l1{1, 2, 3, 5, 11, 16, 0};
    vector<int> l2{10};

    vector<int> l3{};
    vector<int> l4{1, 3, 4, 5, 10};

    vector<int> res = sol.mergesortedarray(l3, l3);
    cout << res;
    // sol.mergesortarray(l1, l2);
    // cout<<l1;

    return 0;
}
