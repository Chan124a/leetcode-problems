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
    int lengthOfLastWord(string s) {
        bool flag = false;
        int ans = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (!flag&&s[i] != ' ') {
                flag = true;
            }
            if (flag && s[i] != ' ')ans++;
            if (flag && s[i] == ' ')break;
        }
        return ans;
    }
};