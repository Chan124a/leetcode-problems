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
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int jin = 0;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            int c;
            if (i == n - 1) {
                c = digits[i] + 1;
            }
            else {
                c = digits[i]+jin;
            }
            jin = c / 10;
            if (jin > 0) {
                c -= 10;
            }
            ans.push_back(c);
        }
        if (jin > 0)ans.push_back(jin);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};