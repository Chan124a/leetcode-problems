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
    int numTrees(int n) {
       vector<int> dp(n+1);
       dp[0] = 1;
       dp[1] = 1;
       for (int i = 2; i <= n; i++)
           for (int j = 0; j < i; j++)
               dp[i] += dp[j] * dp[i - 1 - j];
       return dp[n];
    }
};
int main() {
    int s = Solution().numTrees(3);
}