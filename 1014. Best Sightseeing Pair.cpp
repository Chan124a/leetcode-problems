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
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int m = INT_MIN, ans = INT_MIN;
        for (int i = 0; i < A.size(); i++) {
            ans = max(ans, m + A[i] - i);
            m = max(m, A[i] + i);
        }
        return ans;
    }
};