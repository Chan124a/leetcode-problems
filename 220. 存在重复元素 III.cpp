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
#include <unordered_set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <math.h>
#include <bitset>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0)return false;
        unordered_map<long long, long long> ha;
        long long mod = t + 1LL;
        for (int i = 0; i < nums.size(); i++)
        {
            long long idex = nums[i] / mod;
            if (nums[i] < 0)idex--;
            if (ha.find(idex) != ha.end())return true;
            else if (ha.find(idex - 1) != ha.end() && abs(ha[idex - 1] - nums[i]) <= t)return true;
            else if (ha.find(idex + 1) != ha.end() && abs(ha[idex + 1] - nums[i]) <= t)return true;
            ha[idex] = nums[i];
            if (i >= k)ha.erase(nums[i - k] / mod);
        }
        return false;
    }
};