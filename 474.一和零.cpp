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
    int findMaxForm(vector<string>& strs, int m, int n) {
        int count = strs.size();
        vector<vector<int>> st(count, vector<int>(2, 0));
        for (int i = 0; i < count; i++)
        {
            string temp = strs[i];
            for (int j = 0; j < temp.size(); j++)
            {
                /* code */
                if (temp[j] == '1')st[i][0]++;
                else st[i][1]++;
            }
        }
        vector<vector<vector<int>>> dp(count + 1, vector<vector<int>>(n + 1, vector<int>(m + 1, 0)));
        for (int i = 1; i <= count; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= m; k++) {
                    if (j - st[i - 1][0] < 0 || k - st[i - 1][1] < 0)
                        dp[i][j][k] = dp[i - 1][j][k];
                    else 
                        dp[i][j][k] = max(dp[i - 1][j][k], 1 + dp[i - 1][j - st[i - 1][0]][k - st[i - 1][1]]);
                }
            }
        }
        return dp[count][n][m];
    }
};
int main() {
    vector<string> strs = vector<string>{ "10","0001","111001","1","0" };
    // cout<<"hh"<<endl;
    // vector<string> strs={"10","0001","111001","1","0"};
    int x = Solution().findMaxForm(strs, 5, 3);
    return 1;
}