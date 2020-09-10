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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ha;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> res;
        for (int i = 0; i < n1; i++)
        {
            if (ha[nums1[i]] == 0)ha[nums1[i]] = 1;
            else ha[nums1[i]] ++;
        }
        for (int i = 0; i < n2; i++)
        {
            if (ha[nums2[i]] != 0) {
                res.push_back(nums2[i]);
                ha[nums2[i]]--;
            }
        }
        return res;
    }
};