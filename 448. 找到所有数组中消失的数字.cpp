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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size() ; i++)
        {
            if (nums[abs(nums[i]) - 1] > 0)nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)res.push_back(i + 1);
        }
        return res;
    }
};