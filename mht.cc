#include "utils.h"

class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return vector<int>{0};

        vector<unordered_set<int>> graph(n);

        for (auto edge : edges) {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }

        vector<int> leaves;

        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 1) leaves.push_back(i);
        }

        while (n > 2) {
            n -= leaves.size();

            vector<int> new_leaves;

            for (auto l : leaves) {
                int adj = *(graph[l].begin());
                graph[adj].erase(l);
                // graph.erase(adj);
                if (graph[adj].size() == 1) new_leaves.push_back(adj);
            }

            leaves = new_leaves;
        }

        return leaves;
    }
};
