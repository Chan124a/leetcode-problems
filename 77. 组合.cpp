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
#include <unordered_map>
#include <time.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& ans,vector<int>temp, int n, int k, int idex,int depth) {
        if (depth == k) {
            temp.push_back(idex);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(idex);
        for (int i = idex+1; i <= n; i++)
        {
            dfs(ans, temp, n, k, i, depth + 1);
        }
        temp.pop_back();
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <=0)return {};
        vector<vector<int>> ans;
        vector<int> temp;
        if (k >= n) {
            for (int i = 1; i <= n; i++)
            {
                temp.push_back(i);
            }
            ans.push_back(temp);
            return ans;
        }
        for(int i=1;i<=n;i++)
            dfs(ans, temp, n, k, i, 1);
        return ans;
    }
};
int main() {
    vector<vector<int>> ans = Solution().combine(2, 2);
    return 0;
}