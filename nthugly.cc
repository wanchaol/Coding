class Solution {
   public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;

        vector<int> res(n);

        int t2 = 0, t3 = 0, t5 = 0;

        res[0] = 1;

        for (int i = 1; i < n; ++i) {
            res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));

            if (res[i] == res[t2] * 2) ++t2;
            if (res[i] == res[t3] * 3) ++t3;
            if (res[i] == res[t5] * 5) ++t5;
        }

        return res[n - 1];
    }
};
