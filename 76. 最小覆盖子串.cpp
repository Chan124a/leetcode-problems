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
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for (char c : t)need[c]++;
        int right = 0, left = 0;
        int match = 0;
        int minLen = INT_MAX,start=0;
        while (right<s.size())
        {
            char c1 = s[right];
            if (need.count(c1)) {
                window[c1]++;
                if (window[c1] == need[c1])match++;
            }
            right++;
            while (match==need.size())
            {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                char c2 = s[left];
                if(need.count(c2)){
                    window[c2]--;
                    if (window[c2] < need[c2])match--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};