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
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 0; i < n; i++) {
            vector<int> temp = ans;
            reverse(temp.begin(), temp.end());
            for (auto t : temp) {
                t += (1 << i);
                ans.push_back(t);
            }
        }
        return ans;
    }
};