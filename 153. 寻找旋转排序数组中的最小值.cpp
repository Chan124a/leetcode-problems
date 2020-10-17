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
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if (nums[l] < nums[r])return nums[l];
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] >= nums[0])l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};