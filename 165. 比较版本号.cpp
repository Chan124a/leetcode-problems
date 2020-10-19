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
    int compareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0;
        int len = max(version1.size(), version2.size());
        while (p1 < len || p2 < len) {
            int v1 = 0, v2 = 0;
            while (p1 < version1.size() && version1[p1] != '.')
            {
                v1 = v1 * 10 + version1[p1] - '0';
                p1++;
            }
            while (p2 < version2.size() && version2[p2] != '.')
            {
                v2 = v2 * 10 + version2[p2] - '0';
                p2++;
            }
            if (v1 < v2)return -1;
            else if (v1 > v2)return 1;
            p1++;
            p2++;
        }
        return 0;
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
        string version1 = stringToString(line);
        getline(cin, line);
        string version2 = stringToString(line);

        int ret = Solution().compareVersion(version1, version2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}