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
using namespace std;
class Solution {
    void back(vector<string>& res, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            res.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            back(res, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            back(res, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        back(res, cur, 0, 0, n);
        return res;
    }
};


