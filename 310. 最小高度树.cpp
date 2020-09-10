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
#include <set>
#include <map>
#include <unordered_map>
#include <time.h>
using namespace std;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 0)return {};
        int len = edges.size();
        vector<vector<int>> graph(n,vector<int>());
        vector<int> rd(n,0);
        for (int i = 0; i < len; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
            rd[a]++;
            rd[b]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (rd[i] == 1)q.push(i);
        }
        int res = n;
        if (n == 1)return { 0 };
        while (res!=1&&res!=2)
        {
            int len = q.size();
            res -= len;
            for (int i = 0; i < len; i++)
            {
                int temp = q.front();
                q.pop();
                for (int j = 0; j < graph[temp].size(); j++)
                {
                    rd[graph[temp][j]]--;
                    if (rd[graph[temp][j]] == 1)q.push(graph[temp][j]);
                }
            }
        }
        vector<int> a;
        while (!q.empty())
        {
            a.push_back(q.front());
            q.pop();
        }
        return a;
    }
};
int main() {
    vector<int> res;
    vector<vector<int>> edges = { {1,0 }, { 1,2 }, { 1,3 }};
    res = Solution().findMinHeightTrees(4,edges);
}