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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0)return 0;
        if (obstacleGrid[0].size() == 0)return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i])dp[0][i] = 0;
            else {
                if (i == 0)dp[0][i] = 1;
                else {
                    dp[0][i] = dp[0][i - 1];
                }
            }
        }
        for (int j = 0; j < m; j++) {
            if (obstacleGrid[j][0])dp[j][0] = 0;
            else {
                if (j == 0)dp[j][0] = 1;
                else {
                    dp[j][0] = dp[j-1][0];
                }
            }
        }
        for (int j = 1; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (obstacleGrid[j][i])dp[j][i] = 0;
                else dp[j][i] = dp[j][i - 1] + dp[j - 1][i];
            }
        }
        return dp[m - 1][n - 1];
    }
};
int main() {
    vector<vector<int>> obstacleGrid = { {1,0} };
    int ans = Solution().uniquePathsWithObstacles(obstacleGrid);
}