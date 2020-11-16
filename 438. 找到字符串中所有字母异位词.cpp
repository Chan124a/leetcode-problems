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
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need;
        unordered_map<char, int>window;
        for (auto i : p)need[i]++;
        int left = 0, right = 0;
        int match = 0;
        vector<int> ans;
        while (right<s.size())
        {
            char c1 = s[right];
            if (need.find(c1) != need.end()) {
                window[c1]++;
                if (window[c1] == need[c1])match++;
            }
            right++;
            while (match==need.size())
            {
                if (right - left == p.size()) {
                    ans.push_back(left);
                }
                char c2 = s[left];
                if (window.find(c2) != window.end()) {
                    window[c2]--;
                    if (window[c2] < need[c2])match--;
                }
                left++;
            }
        }
        return ans;
    }
};