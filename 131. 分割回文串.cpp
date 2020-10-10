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
    vector<vector<string>> ans;
    void dfs(string s, int start,int len, vector<string>path,vector<vector<bool>>& dp) {
        if (start == len) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < len; i++)
        {
            if (!dp[start][i])continue;
            path.push_back(s.substr(start, i - start + 1));
            dfs(s, i + 1, len, path,dp);
            path.pop_back();
        }
        return;
    }
    //bool check(string s, int left, int right) {
    //    int len = (right-left+1) / 2;
    //    for (int i = 0; i <len; i++)
    //    {
    //        if (s[left + i] != s[right - i])return false;
    //    }
    //    return true;
    //}
    vector<vector<string>> partition(string s) {
        if (s.size() == 0)return ans;
        vector<string> path;
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len));
        for(int j=0;j<len;j++)
            for (int i = 0; i <= j; i++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]))dp[i][j] = true;
                else dp[i][j] = false;
            }
        dfs(s, 0, len, path,dp);
        return ans;
    }
};
