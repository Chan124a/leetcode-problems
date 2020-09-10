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
#include <map>`
#include <unordered_map>
#include <time.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)return 0;
        if (divisor == 1)return dividend;
        if (divisor == -1) {
            if (dividend > INT_MIN)return -dividend;
            else return INT_MAX;
        }
        bool flag = false;
        if ((dividend < 0&&divisor>0)||(dividend>0&&divisor<0)) {
            flag = true;
        }
        long a = abs(dividend);
        long b = abs(divisor);
        int ans = dfs(a, b);
        if (flag)return -ans;
        else return ans;
    }
    int dfs(long a,long b) {
        if (a < b)return 0;
        long tb = b;
        int count = 1;
        while (tb+tb<a)
        {
            tb += tb;
            count+=count;
        }
        return count + dfs(a - tb,b);
    }
};