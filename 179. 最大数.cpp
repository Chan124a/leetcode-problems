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
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (all_of(nums.begin(), nums.end(), [](int x) {return x == 0; })) {
            return string("0");
        }
        vector<string> strNums(nums.size());
        std::transform(nums.begin(), nums.end(), strNums.begin(), [](int x) {return std::to_string(x); });
        std::sort(strNums.begin(), strNums.end(), [](const string& x, const string& y) {
            return x + y > y + x;
            });
        return std::accumulate(strNums.begin(), strNums.end(), string());
    }
};