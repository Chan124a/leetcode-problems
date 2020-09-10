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
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        if (n1 == 0)return true;
        int count = 0;
        for (int i = 0; i < n2; i++) {
            if (s[count] == t[i]) {
                count++;
                if (count == n1)return true;
            }
        }
        return false;
    }
    //下面的解法适用于大量数据判断
    //bool isSubsequence(string s, string t) {
    //    vector<vector<int>> dp(26);
    //    int tag = -1;
    //    for (int i = 0; i < t.size(); i++)
    //        dp[t[i] - 'a'].push_back(i);
    //    for (int i = 0; i < s.size(); i++)
    //    {
    //        int now = s[i] - 'a';
    //        int left = 0, right = dp[now].size() - 1;
    //        while (left<right)
    //        {
    //            int mid = (left + right) / 2;
    //            if (dp[now][mid] > tag)right = mid;
    //            else left = mid + 1;
    //        }
    //        if (left > right || dp[now][left] <= tag)return false;
    //        tag = dp[now][left];
    //    }
    //    return true;
    //}
};
bool isSubsequence(string s, string t) {
    vector<vector<int>>dp(26);
    int tag = -1;
    for (int i = 0; i < t.size(); i++)
        dp[t[i] - 'a'].push_back(i);
    for (int i = 0; i < s.size(); i++) {
        int now = s[i] - 'a';
        int left = 0, right = dp[now].size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (dp[now][mid] > tag)
                right = mid;
            else
                left = mid + 1;
        }
        if (right < left || dp[now][left] <= tag)return false;
        tag = dp[now][left];

    }
    return true;
}

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
            case '\"': result.push_back('\"'); break;
            case '/': result.push_back('/'); break;
            case '\\': result.push_back('\\'); break;
            case 'b': result.push_back('\b'); break;
            case 'f': result.push_back('\f'); break;
            case 'r': result.push_back('\r'); break;
            case 'n': result.push_back('\n'); break;
            case 't': result.push_back('\t'); break;
            default: break;
            }
            i++;
        }
        else {
            result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);

        bool ret = Solution().isSubsequence(s, t);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}