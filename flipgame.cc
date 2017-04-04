#include "utils.h"

class Solution {
   public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res{};

        if (s.size() == 0) return res;

        // cout<<s.size() << " "<< s.size() - 1<<endl;

        for (size_t i = 0; i < s.size() - 1; ++i) {
            if (s[i] != '+') continue;

            if (s[i + 1] == '+') {
                string temp = s;
                temp[i] = '-';
                temp[i + 1] = '-';

                res.push_back(temp);
            }
        }

        return res;
    }

   private:
    /* data */
};

int main(int argc, char *argv[]) {
    Solution sol;

    cout << sol.generatePossibleNextMoves("");

    return 0;
}
