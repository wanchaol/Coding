#include "../utils.h"

int mincost(vector<vector<int>> &costs) {
    if (costs.empty()) {
        return 0;
    }
    int r = 0, g = 0, b = 0;

    for (size_t i = 0; i < costs.size(); ++i) {
        int rr = r, gg = g, bb = b;

        r = costs[i][0] + min(gg, bb);
        b = costs[i][1] + min(rr, gg);
        g = costs[i][2] + min(rr, bb);
    }

    return min(r, min(g, b));
}
