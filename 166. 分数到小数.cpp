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
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans="";
        if (numerator == 0)return "0";
        if (denominator == 1)return to_string(numerator);
        if (denominator == -1) {
            long long x = -numerator;
            return to_string(x);
        }
        if ((numerator > 0 && denominator < 0)|| (numerator < 0 && denominator>0)) {
            ans += "-";
        }
        long long de = abs(denominator);
        long long nu = abs(numerator);
        long long  x;
        map<int,int>yu;
        if (nu > de) {
            int y = nu / de;
            ans += to_string(y);
            x = nu- de*y;
            if (x == 0)return ans;
        }
        else {
            ans += "0";
            x = nu;
        }
        ans += ".";
        string temp;
        int count = 0;
        while (x!=0)
        {
            yu[x] = count++;
            x = x * 10;
            long long  y = x / de;
            temp += to_string(y);
            x = x - y * de;
            if (yu.find(x) != yu.end()) {
                ans = ans +temp.substr(0,yu[x])+"("+temp.substr(yu[x],yu.size()-yu[x])+")";
                return ans;
            }
        }
        return ans+temp;
    }
};
int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int numerator = stringToInteger(line);
        getline(cin, line);
        int denominator = stringToInteger(line);

        string ret = Solution().fractionToDecimal(numerator, denominator);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}