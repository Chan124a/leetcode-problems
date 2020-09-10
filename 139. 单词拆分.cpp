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
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        int lenStr = s.length();
        vector<bool> dp(lenStr + 1, false);
        dp[0] = true;
        for (int i = 1 ; i <=lenStr; i++)
        {
            for (int j = i; j >=0; j--)
            {
                string lst = s.substr(j, i - j);
                if (st.find(lst) != st.end() && dp[j] == true) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[lenStr];
    }
};
