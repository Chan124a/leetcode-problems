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
    int majorityElement(vector<int>& nums) {
        int j = 0,max;
        for (int i = 0; i < nums.size(); i++) {
            if (j == 0)max = nums[i];
            if (nums[i] == max)j++;
            else j--;
        }
        return max;
    }
};