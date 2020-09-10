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
    double quickMul(double x, long long n) {
        if (n == 0)return 1.0;
        double y = quickMul(x, n / 2);
        return n%2==0?y*y:y*y*x;
    }
    double myPow(double x, int n) {
        long long N = n;
        return N > 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
int main() {
    //double ans = Solution().myPow(2.00000, 10);
    double ans = Solution().myPow(1, -2147483648);
    return 0;
}