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
#include <map>
#include <unordered_map>
#include <time.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> p;
        p['I'] = 1,p['V'] = 5,p['X'] = 10,p['L'] = 50,p['C'] = 100,p['D'] = 500,p['M'] = 1000;
        int len = s.size();
        if (len == 0)return 0;
        if (len == 1)return p[s[0]];
        int i = 1, res = 0;
        while (i<len)
        {
            int a = p[s[i - 1]];
            int b = p[s[i]];
            if (a == b||a>b)res += a;
            else {
                res += (b - a);
                i++;
            }
            i++;
        }
        if (i == len)res += p[s[i-1]];
        return res;
    }
};
string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
            case '\"': result.push_back('\"'); break;
            case '/': result.push_back('/'); break;
            case '\\': result.push_back('\\'); break;
            case 'b': result.push_back('\b'); break;
            case 'f': result.push_back('\f'); break;
            case 'r': result.push_back('\r'); break;
            case 'n': result.push_back('\n'); break;
            case 't': result.push_back('\t'); break;
            default: break;
            }
            i++;
        }
        else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().romanToInt(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}