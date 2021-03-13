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
    int trap(vector<int>& height) {
        if (height.empty())return 0;
        int n = height.size();
        int l_max = height[0], r_max = height[n - 1];
        int left = 0, right = n - 1;
        int ans = 0;
        while (left<=right)
        {
            l_max = max(height[left], l_max);
            r_max = max(height[right], r_max);
            if (l_max < r_max) {
                ans += l_max - height[left];
                left++;
            }
            else
            {
                ans += r_max - height[right];
                right--;
            }
        }
        return ans;
    }
};