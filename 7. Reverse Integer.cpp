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
    int reverse(int x) {
        if (x == 0x80000000)return 0;
        if (x == 0)return 0;
//        vector<int> res;
        int a;
        long res = 0;
        if (x < 0)a = -x;
        else a = x;
        while (a!=0)
        {   
            res = res * 10 + a % 10;
            a /= 10;
            if (res >= 0x7fffffff) {
                res = 0;
                break;
            }
        }
        if (x < 0)return -res;
        else return res;
    }
};
int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}