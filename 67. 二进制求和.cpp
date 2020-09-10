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
    string addBinary(string a, string b) {
        string ans = "";
        int len1 = a.size(), len2 = b.size();
        int jin = 0;
        int i;
        for ( i = 0; i < len1&&i<len2; i++)
        {
            int s1 = a[len1 - i - 1]-'0', s2 = b[len2 - i - 1]-'0';
            int c = s1 + s2 + jin;
            jin = c / 2;
            if (jin > 0)c -= 2;
            ans = to_string(c)+ans;
        }
        while (i < len1) {
            int c = a[len1 - i - 1] - '0' + jin;
            jin = c / 2;
            if (jin > 0)c -= 2;
            ans = to_string(c) + ans;
            i++;
        }
        while (i < len2) {
            int c = b[len2 - i - 1] - '0' + jin;
            jin = c / 2;
            if (jin > 0)c -= 2;
            ans = to_string(c) + ans;
            i++;
        }
        if (jin != 0)ans = to_string(jin) + ans;
        return ans;
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
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);

        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}