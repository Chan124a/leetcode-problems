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
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)return 0;
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (i==1)
            {
                dp[i] = max(dp[0],nums[i]);
                continue;
            }
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
};