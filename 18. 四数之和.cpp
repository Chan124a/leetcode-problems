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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            while(j<nums.size()){
                //if (nums[j] > target - nums[i])break;
                int left = j + 1, right = nums.size() - 1;
                while(left < right) {
                    long long x = static_cast<long long> (nums[j]);
                    long long y = static_cast<long long>(nums[left]);
                    long long z = static_cast<long long>(nums[right]);
                    if (x + y + z > target - nums[i]) {
                        while (left < right && nums[right - 1] == nums[right])right--;
                        right--;
                    }
                    else if (x + y + z < target - nums[i]) {
                        while(left < right&& nums[left + 1] == nums[left])left++;
                        left++;
                    }else{
                        ans.push_back({nums[i], nums[j],nums[left],nums[right]});
                        while (left < right && nums[right - 1] == nums[right])right--;
                        while (left < right && nums[left + 1] == nums[left])left++;
                        left++;
                    }
                }
                while (j +1< nums.size() && nums[j + 1] == nums[j])j++;
                j++;
            }
            while (i +1< nums.size() && nums[i + 1] == nums[i])i++;
        }
        return ans;
    }
};
int main() {
    vector<int> nums = { 1, -2, -5, -4, -3, 3, 3, 5 };
    int target = -11;
    vector<vector<int>> res;
    res = Solution().fourSum(nums, target);
    return 0;
}
