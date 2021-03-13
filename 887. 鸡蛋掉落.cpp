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
    int dfs(vector<vector<int>>& dp,int k, int n) {
        if (k == 1)return n;
        if (n == 0)return 0;
        if (dp[k][n] != -2)return dp[k][n];
        int temp = INT_MAX;
        for (int i = 1; i <=n; i++)
        {
            temp = min(temp,1+ max(dp[k][n - i], dp[k - 1][i - 1]));
        }
        dp[k][n] = temp;
        return temp;
    }
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1, vector<int>(N + 1, -2));
        return dfs(dp, K, N);

    }
};
int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int K = stringToInteger(line);
        getline(cin, line);
        int N = stringToInteger(line);

        int ret = Solution().superEggDrop(K, N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
public int superEggDrop(int K, int N) {
    int[][] memo = new int[K + 1][N + 1];
    for (int[] item : memo) {
        Arrays.fill(item, -1);
    }
    return superEggDropMemo(K, N, memo);
}

public int superEggDropMemo(int K, int N, int[][] memo) {
    if (K == 1) {
        return N;
    }
    if (N == 0) {
        return 0;
    }
    if (memo[K][N] != -1) {
        return memo[K][N];
    }

    int res = Integer.MAX_VALUE;
    for (int i = 1; i <= N; i++) {
        res = Math.min(res, Math.max(superEggDropMemo(K - 1, i - 1, memo), superEggDropMemo(K, N - i, memo)) + 1);
    }
    memo[K][N] = res;
    return res;
}