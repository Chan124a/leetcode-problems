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
    int countPrimes(int n) {
        if (n == 0 || n == 1)return 0;
        vector<bool> ha(n+1);
        int ans = 0;
        for (int i = 2; i < n; i++)
        {
            if (ha[i])continue;
            ans++;
            for (int j = 2*i; j < n; j+=i)
            {
                ha[j] = true;
            }
        }
        return ans;
    }
};