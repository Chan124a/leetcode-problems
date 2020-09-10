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
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1 = g.size();
        int n2 = s.size();
        if (n1 == 0 || n2 == 0)return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0, res = 0;
        for (int i = 0; i < n1; i++)
        {
            for (; j < n2; j++) {
                if (g[i]<=s[j])
                {
                    res++;
                    j++;
                    break;
                }
            }
        }
        return res;
    }
};