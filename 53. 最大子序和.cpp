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
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxS = INT_MIN;
        bool flag = false;
        int maxF = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0) {
                flag = true;
            }
            else {
                if (nums[i] > maxF)maxF = nums[i];
            }
            sum += nums[i];
            if (sum >= 0) {
                if (sum > maxS)maxS = sum;
            }
            else {
                sum = 0;
            }
        }
        if (flag)return maxS;
        else return maxF;
    }
};