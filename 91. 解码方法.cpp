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
#include <map>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0)return 0;
        if (s[0] == '0')return 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            int c = 0;
            if (i == 0) {
                dp[i] = 1;
            }
            else if (i == 1) {
                c = (s[0] - '0') * 10 + (s[1] - '0');
                if (s[i] == '0') {
                    if (c <= 26)dp[i] = 1;
                    else return 0;
                }
                else
                {
                    if (c <= 26)dp[i] = 2;
                    else dp[i] = 1;
                }
            }
            else
            {
                c = (s[i-1] - '0') * 10 + (s[i] - '0');
                if (s[i] == '0') {
                    if (s[i - 1] == '0')return 0;
                    else {
                        if (c <= 26)dp[i] = dp[i - 2];
                        else return 0;
                    }
                }
                else
                {
                    if (s[i-1] == '0')dp[i] = dp[i - 1];
                    else {
                        if (c <= 26)dp[i] = dp[i - 2] + dp[i - 1];
                        else dp[i] = dp[i - 1];
                    }
                }
            }
        }
        return dp[n - 1];
    }
};