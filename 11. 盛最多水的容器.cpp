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
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int res = 0;
        while (left<right)
        {
            int h, d = right - left;
            if (height[left] < height[right]) {
                h = height[left];
                left++;
            }
            else {
                h = height[right];
                right--;
            }
            int max = h * d;
            if (max > res)res = max;
        }
        return res;
    }
};