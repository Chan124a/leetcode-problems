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
#include <bitset>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> ha1;
        map<char, char> ha2;
        int len1 = s.size(), len2 = t.size();
        if (len1 != len2)return false;
        for (int i = 0; i < len1; i++)
        {
            char c1 = s[i], c2 = t[i];
            if (ha1.find(c1) != ha1.end()||ha2.find(c2)!=ha2.end()) {
                if (ha1[c1] != c2||ha2[c2]!=c1)return false;
            }
            else
            {
                ha1[c1] = c2;
                ha2[c2] = c1;
            }
        }
        return true;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);

        bool ret = Solution().isIsomorphic(s, t);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}