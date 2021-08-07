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
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)return nums[0];
        int dp1,dp2;
        int d;
        for (int i = 0; i < n-1; i++)
        {
            if (i == 0) {
                dp1= nums[i];
                d = nums[i];
                continue;
            }
            if (i == 1) {
                dp1 = max(dp1, nums[i]);
                continue;
            }
            int temp = dp1;
            dp1 = max(d + nums[i], dp1);
            d = temp;
        }
        for (int i = 1; i < n; i++)
        {
            if (i == 1) {
                dp2 = nums[i];
                d = nums[i];
                continue;
            }
            if (i == 2) {
                dp2 = max(dp2, nums[i]);
                continue;
            }
            int temp = dp2;
            dp2 = max(d + nums[i], dp2);
            d = temp;
        }
        return max(dp1, dp2);
    }
};