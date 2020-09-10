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
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        long p = 5;
        int count = 0;
        while (p <= n) {
            count += (n / p);
            p *= 5;
        }
        return count;
    }
};