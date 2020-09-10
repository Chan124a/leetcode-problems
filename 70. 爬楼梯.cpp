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
    vector<int> ha;
    int fei(int n) {
        if (ha[n] != 0)return ha[n];
        else {
            ha[n] = fei(n - 1) + fei(n - 2);
            return ha[n];
        }
    }
    int climbStairs(int n) {
        ha.resize(n+1);
        ha[0] = 1, ha[1] = 1;
        return fei(n);
    }
};
int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}