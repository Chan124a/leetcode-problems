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
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l<=r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)return true;
            if (nums[l] == nums[mid]) {
                l++;
                continue;
            }
            else if (nums[l]< nums[mid]) {
                if (target >= nums[l] && target < nums[mid])r = mid - 1;
                else l = mid + 1;
            }
            else {
                if (target <= nums[r] && target > nums[mid])l = mid + 1;
                else r = mid - 1;
            }
        }
        return false;
    }
};