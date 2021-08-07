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

////前向动态规划
//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        int lens = s.size(), lenp = p.size();
//        //dp[0][0]表示s长度为0，p长度为0的情况。dp[i][j]表示s[0,i]（注意：不包括位置i,下标i表示结束位置）与p[0,j]是否匹配
//        vector<vector<bool>> dp(lens+1, vector<bool>(lenp+1));
//        for (int i = 0; i <= lens; i++)
//        {
//            for (int j = 0; j <= lenp; j++) {
//                //当s和p为空串时，显然是匹配的
//                if (i == 0 && j == 0) {
//                    dp[i][j] = true;
//                    continue;
//                }
//                //边界条件，当j=0，i=1,2,3,4,...时，由于模式串p为空串，所以不匹配。
//                //当i=0，j=1时，字符串s为空，匹配串p只有一个字符，显然也不匹配
//                if (j == 0||(i==0&&j==1)) {
//                    dp[i][j] = false;
//                    continue;
//                }
//                //i=0表示字符串s为空，这时匹配串p由于*可以表示没有匹配，所以p还是可能与空串s匹配的
//                if (i == 0) {
//                    if (p[j - 1] == '*')dp[i][j] = dp[i][j - 2];
//                    else dp[i][j] = false;
//                    continue;
//                }
//                //当字符相等、或者p对应字符为'.'，则考虑字符串s和模式串p前一位是否匹配即可
//                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
//                    dp[i][j] = dp[i - 1][j - 1];
//                }
//                //当p对应字符为‘*’,要考虑各种情况
//                else if (p[j - 1] == '*') {
//                    //当‘*’前面的字符与字符串s匹配，或者‘*’前面的字符为‘.’，则‘*’和前面的字符可以匹配模式串s的1位字符或者0位字符
//                    //当匹配1个字符（即可以吃掉一个字符），则检查s前一位字符是否匹配
//                    //当匹配0个字符，由于*可以表示0个匹配，所以模式串p的指标往前退两个即可
//                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
//                        dp[i][j] = dp[i - 1][j] | dp[i][j-2];
//                    }
//                    else dp[i][j] = dp[i][j - 2];
//                }
//                else dp[i][j] = false;
//            }
//        }
//        return dp[lens][lenp];
//    }
//};

//后向动态规划
class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.size(), lenp = p.size();
        vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1));
        for (int i = lens; i>=0; i--)
        {
            for (int j = lenp; j >=0; j--) {
                if (i == lens && j == lenp) {
                    dp[i][j] = true;
                    continue;
                }
                if (j == lenp || (i == lens && j == lenp - 1)) {
                    dp[i][j] = false;
                    continue;
                }
                if (i == lens) {
                    if (j < lenp - 1 && p[j + 1] == '*')dp[i][j] = dp[i][j + 2];
                    else dp[i][j] = false;
                    continue;
                }
                if (s[i] == p[j] || p[j] == '.') {
                    if (j + 1 < lenp && p[j + 1] == '*')dp[i][j] = dp[i + 1][j] | dp[i][j + 2];
                    else dp[i][j] = dp[i + 1][j + 1];
                }
                else if (j + 1 < lenp && p[j + 1] == '*')dp[i][j] = dp[i][j + 2];
                else dp[i][j] = false;
            }
        }
        return dp[0][0];
    }
};
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
        string p = stringToString(line);

        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}