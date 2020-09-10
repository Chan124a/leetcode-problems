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
#include <map>`
#include <unordered_map>
#include <time.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        for (int i = len - 1; i >= 1; i--) {
            if (nums[i - 1] < nums[i]) {
                int k = len - 1;
                while (nums[k] <= nums[i - 1])k--;
                swap(nums[i - 1], nums[k]);
                sort(nums.begin()+i, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
        return;
    }
};