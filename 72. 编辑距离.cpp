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
#include <unordered_set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <math.h>
#include <bitset>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n+1));
        for (int i = 0; i <= m; i++)   dp[i][0] = i;
        for (int i = 0; i <=n ; i++)    dp[0][i] = i;
        for (int i = 1; i <=m; i++)
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    dp[i][j] = min(dp[i - 1][j],min( dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
            }
        return dp[m][n];
        
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

int main() {
    string line;
    while (getline(cin, line)) {
        string word1 = stringToString(line);
        getline(cin, line);
        string word2 = stringToString(line);

        int ret = Solution().minDistance(word1, word2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}