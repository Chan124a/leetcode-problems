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
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1)return true;
        int left = 1, right = num;
        while (left <= right)
        {
            long long  mid = ((long long)left + right) / 2;
            long long x = mid * mid;
            if (x == num)return true;
            else if (x < num)left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        bool ret = Solution().isPerfectSquare(num);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}