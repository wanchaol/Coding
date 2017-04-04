#include "utils.h"

class Solution {
   public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n == -1) return 1 / x;

        int res = n % 2;
        double temp = myPow(x, n / 2);

        return temp * temp * myPow(x, res);
    }
};
