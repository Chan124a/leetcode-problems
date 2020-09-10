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
#include <unordered_map>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)return 0;
        if (x < 4)return 1;
        int left = 0, right = x/2;
        while (left<right)
        {
            int mid = (left + right) / 2;
            if ((long long)mid * mid < x)left = mid+1;
            else right = mid;
        }
        if ((long long)left * left > x)return left - 1;
        else return left;
    }
};
int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}