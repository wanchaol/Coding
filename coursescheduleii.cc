#include "utils.h"

class Solution {
   private:
    vector<unordered_set<int>> make_graph(
        int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);

        for (auto edge : prerequisites) {
            graph[edge.second].insert(edge.first);
        }

        return graph;
    }

    vector<int> computeIndegrees(vector<unordered_set<int>>& graph) {
        vector<int> indegrees(graph.size(), 0);

        for (auto adj : graph) {
            for (auto nei : adj) {
                ++indegrees[nei];
            }
        }

        return indegrees;
    }

   public:
    vector<int> findOrder(int numCourses,
                          vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph =
            make_graph(numCourses, prerequisites);
        vector<int> indegrees = computeIndegrees(graph);
        vector<int> toporder;
        vector<int> forder;

        for (int i = 0; i < numCourses; ++i) {
            int j = 0;

            for (; j < numCourses; ++j) {
                if (!indegrees[j]) break;
            }

            if (j == numCourses) return toporder;

            forder.push_back(j);
            indegrees[j] = -1;
            for (int neigh : graph[j]) --indegrees[neigh];
        }

        toporder = forder;

        return toporder;
    }
};
