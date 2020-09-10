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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> h;
        int co = 0;
        for (auto str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            if (h.count(temp)) {
                res[h[temp]].push_back(str);
            }
            else {
                h[temp] = co++;
                vector<string> e(1, str);
                res.push_back(e);
            }
        }
        return res;
    }
};

