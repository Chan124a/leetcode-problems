#include <stack>
#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_set>
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector <int>> res;
        vector<int> chase;
        int n = graph.size();
        vector<bool> visited(n);
        dfs(graph,visited,0,n-1,chase,res);
        return res;
    }
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int start, int end,vector<int>& chase, vector<vector <int>> &res) {
        if (start == end) {
            chase.push_back(start);
            res.push_back(chase);
            chase.pop_back();
            return;
        }
        chase.push_back(start);
        if (visited[start])return;
        visited[start] = true;
        for (int i = 0; i < graph[start].size(); i++)
        {
            dfs(graph, visited, graph[start][i], end, chase,res);
        }
        visited[start] = false;
        chase.pop_back();
    }
};