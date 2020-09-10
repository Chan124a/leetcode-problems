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
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector < vector<int>> ans;
        ans.push_back(nums);
        int i = nums.size() - 1;
        while(i>0) {
            if (nums[i] > nums[i - 1]) {
                int k = nums.size() - 1;
                while (k >= i && nums[k] < nums[i - 1])k--;
                swap(nums[i - 1], nums[k]);
                sort(nums.begin() + i, nums.end());
                ans.push_back(nums);
                i = nums.size() - 1;
            }
            else i--;
        }
        return ans;
    }
};