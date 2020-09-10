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
    string getPermutation(int n, int k) {
        string ans="";
        for (int i = 1; i <= n; i++)ans += to_string(i);
        while (--k)
        {
            int i = ans.size() - 1, j = ans.size() - 1;
            while (i > 0 && ans[i] < ans[i - 1])i--;
            while (j >= i && ans[j] < ans[i - 1])j--;
            swap(ans[i - 1], ans[j]);
            sort(ans.begin() + i, ans.end());
        }
        return ans;
    }
};