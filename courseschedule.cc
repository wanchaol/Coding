#include "utils.h"


class Solution {
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        
        for(auto edge: prerequisites) {
            graph[edge.second].insert(edge.first);
        }
        
        return graph;
    }
    
    vector<int> computeIndegrees(vector<unordered_set<int>> &graph) {
        vector<int> indegrees(graph.size(), 0);
        
        for(auto adj: graph) {
            for(auto nei: adj) {
                ++ indegrees[nei];
            }
        }
        
        return indegrees;
    }
    
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> indegrees = computeIndegrees(graph);
        
        for(auto edge: indegrees) {
            
            int j = 0;
            
            for(; j < numCourses; ++ j) {
                if(indegrees[j] == 0)
                    break;
            }
            //cannot find 
            if(j == numCourses)
                return false;
            
            indegrees[j] = -1;
            for(int neigh: graph[j]) {
                -- indegrees[neigh];
            }
        }
        
        return true;
        
    }
};
