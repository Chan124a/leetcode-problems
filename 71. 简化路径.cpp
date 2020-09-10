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
    string simplifyPath(string path) {
        path += "/";
        stack<string> st;
        string dir;
        for (auto s : path) {
            if (s == '/') {
                if (dir == ".." && st.empty())st.pop();
                else if (dir != ".." && dir != "." && !dir.empty())st.push(dir);
            }
            else dir += s;
        }
        string res;
        while(!st.empty())
        {
            auto t = st.top();
            st.pop();
            res += string(t.rbegin(), t.rend()) + "/";
        }
        reverse(res.begin(), res.end());
        if (res.empty())return "/";
        else return res;
    }
};

