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
#include <unordered_set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <math.h>
#include <bitset>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& temp, int idex, int k, int n) {
        if (n == 0&&k==0) {
            ans.push_back(temp);
            return;
        }
        if (n <= 0 || k <= 0)return;
        int t = n / k;
        if (idex+1> t)return;
        for (int i = idex+1; i < 10; i++)
        {
            temp.push_back(i);
            dfs(temp, i, k - 1, n - i);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        dfs(temp, 0, k, n);
        return ans;
    }
};
int main() {
    vector<vector<int>> ans = Solution().combinationSum3(3, 7);
    return 0;
}