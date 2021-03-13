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
    int numSquares(int n) {
        vector<int> dp(n+1);
        for (int i = 1; i <=n; i++)
        {
            dp[i] = i;
            for (int j = 1; i-j*j>=0; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().numSquares(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}