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
    void dfs(vector<vector<int>> &ans, vector<int>&temp, vector<int> nums, int idex, int depth, int k,int n) {
        if (depth == k) {
            temp.push_back(nums[idex-1]);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(nums[idex-1]);
        for (int i = idex + 1; i <=n; i++) {
            dfs(ans, temp, nums, i, depth + 1, k,n);
        }
        temp.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size()==0)return {};
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        ans.push_back(vector<int>(0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dfs(ans, temp, nums, j, 1, i,n);
            }
        }
        return ans;
    }
};
int main() {
    vector<int> s = { 1,2,3 };
    vector<vector<int>> ans = Solution().subsets(s);
    return 0;
}