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
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size())return 0;
        int n1 = grid.size();
        if (!grid[0].size())return 0;
        int n2 = grid[0].size();
        vector<int> ha;
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j <n2; j++) {
                ha.push_back(i * n2 + j);
            }
        }
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                if (grid[i][j]=='0')continue;
                if (j + 1 < n2&&grid[i][j + 1]=='1') {
                    int f1 = find(i * n2 + j,ha);
                    int f2 = find(i*n2+j+1,ha);
                    if (f1 != f2)ha[f2] = ha[f1];
                }
                if (i + 1 < n1&&grid[i + 1][j]=='1') {
                    int f1 = find(i*n2+j, ha);
                    int f2 = find((i+1)*n2+j, ha);
                    if (f1 != f2)ha[f2] = ha[f1];
                }
            }
        }
        //int count = 0;
        unordered_set<int> se;
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                if (grid[i][j]=='0')continue;
                int f = find(i * n2 + j, ha);
                if (se.find(f) == se.end())se.insert(f);
            }
        }
        return se.size();
    }
    int find(int x,vector<int> &ha) {
        int a = x;
        while (ha[x]!=x)
        {
            x = ha[x];
        }
        while (ha[a]!=a)
        {
            int z = ha[a];
            ha[a] = x;
            a = z;
        }
        return x;
    }
};