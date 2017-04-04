#include "utils.h"

class Solution {
   public:
    vector<string> findStrobogrammatic(int n) { return strobohelper(n, n); }

    vector<string> strobohelper(int n, int size) {
        vector<string> res;

        if (n == 0) {
            res.push_back("");
            return res;
        }

        else if (n == 1) {
            res.push_back("0");
            res.push_back("1");
            res.push_back("8");
            return res;
        }

        vector<string> vec = strobohelper(n - 2, size);

        for (auto str : vec) {
            if (n != size) {
                res.push_back("0" + str + "0");
            }

            res.push_back("1" + str + "1");
            res.push_back("6" + str + "9");
            res.push_back("9" + str + "6");
            res.push_back("8" + str + "8");
        }

        return res;
    }
};
