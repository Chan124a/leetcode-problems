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
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for (auto c : s1)need[c]++;
        int left = 0, right = 0;
        int match = 0;
        while (right<s2.size())
        {
            char c = s2[right];
            if (need.find(c) != need.end()) {
                window[c]++;
                if (window[c] == need[c])match++;
            }
            right++;
            while (match==need.size())
            {
                if (right - left == s1.size())return true;
                char temp = s2[left];
                if (window.find(temp) != window.end()) {
                    window[temp]--;
                    if (window[temp] < need[temp])match--;
                }
                left++;
            }
        }
        return false;
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
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);

        bool ret = Solution().checkInclusion(s1, s2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}