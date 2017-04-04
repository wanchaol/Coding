#include "utils.h"

class Solution {
   private:
    map<int, int> umap;

   public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        if (umap[amount]) return umap[amount];

        int mincount = amount + 1;
        for (auto coin : coins) {
            int next = -1;
            if (amount >= coin) next = coinChange(coins, amount - coin);

            if (next >= 0) {
                mincount = min(mincount, next + 1);
            }
        }

        int finalcount = (mincount == amount + 1) ? -1 : mincount;
        umap[amount] = finalcount;

        return finalcount;
    }
};

int main(void) {
    vector<int> coins{224, 2, 217, 189, 79, 343, 101};

    int amount = 2938;

    Solution sol;

    cout << sol.coinChange(coins, amount) << endl;

    return 0;
}
