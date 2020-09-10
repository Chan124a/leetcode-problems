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
    void sortColors(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)swap(nums[i], nums[j++]);
        }
        j = nums.size() - 1;
        for (int i =j; i>=0; i--)
        {
            if (nums[i] == 2)swap(nums[i], nums[j--]);
        }
    }
};