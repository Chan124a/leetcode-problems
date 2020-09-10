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
#include <map>
#include <unordered_map>
#include <time.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector < vector<int>> res;
        int n = nums.size();
        if (n < 3)return {};
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i<n){
            if (nums[i] > 0)break;
            int left = i + 1, right = n - 1;
            while (left<right)
            {
                long long x = static_cast<long long>(nums[i]);
                long long y = static_cast<long long>(nums[left]);
                long long z = static_cast<long long>(nums[right]);
                if (x + y > -z)right--;
                else if (x + y < -z)left++;
                else {
                    res.push_back({ nums[i],nums[left],nums[right] });
                    while (left < right && nums[left] == nums[left + 1])left++;
                    while (left < right && nums[right] == nums[right - 1])right--;
                    left++;
                    right--;
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1])i++;
            i++;
        }
        return res;
    }
};
