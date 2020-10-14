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
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ' ') {
                if (idx != 0)s[idx++] = ' ';
                int end = i;
                while (end<n&&s[end]!=' ')
                    s[idx++] = s[end++];
                reverse(s.begin() + idx - (end - i), s.begin() + idx);
                i = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};