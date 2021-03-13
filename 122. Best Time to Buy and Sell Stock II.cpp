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
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector < vector<int >> dp(prices.size(), vector<int>(2, 0));
        for (int i = 0; i < prices.size(); i++)
        {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[0];
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        }
        return dp[prices.size() - 1][0];
    }
};