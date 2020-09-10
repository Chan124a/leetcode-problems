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
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left =0, right =n-1;
        while (left<=right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)return mid;
            else if (nums[mid] < target)left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};