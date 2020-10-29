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
#include <math.h>
#include <bitset>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask = 1 << 30;
        int ans=0;
        while (mask>0&&(m&mask)==(n&mask))
        {
            ans |= m & mask;
            mask >>= 1;
        }
        return ans;
    }
};