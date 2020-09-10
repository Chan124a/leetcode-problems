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
//class Solution {
//public:
//    void create(vector<int>& next, string needle) {
//        next[0] = -1;
//        int j = -1;
//        for (int i = 1; i < needle.size(); i++)
//        {
//            while (j != -1 && needle[i] != needle[j + 1])j = next[j];
//            if (needle[i] == needle[j + 1])j++;
//            next[i] = j;
//        }
//    }
//    int strStr(string haystack, string needle) {
//        if (needle.size() == 0)return 0;
//        if (haystack.size() == 0)return -1;
//        int n = haystack.size(), m = needle.size();
//        vector<int> next(m);
//        create(next, needle);
//        int j = -1;
//        for (int i = 0; i < n; i++) {
//            while (j != -1 && haystack[i] != needle[j + 1])j = next[j];
//            if (haystack[i] == needle[j + 1])j++;
//            if (j == m - 1)return i - m+1;
//        }
//        return -1;
//    }
//};

//下面是sunday算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())return 0;
        int s1 = haystack.size();
        int s2 = needle.size();
        int i = 0;
        int j = 0;
        int k;
        int m = s2;
        while (i < s1) {
            if (haystack[i] != needle[j]) {
                if (m > s1)return -1;
                for (k = s2 - 1; k >= 0; k--) {
                    if (needle[k] == haystack[m])break;
                }
                i = m - k;
                j = 0;
                m = i + s2;
            }
            else {
                if (j == s2 - 1)return i - j;
                i++;
                j++;
            }
        }
        return -1;
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
        string haystack = stringToString(line);
        getline(cin, line);
        string needle = stringToString(line);

        int ret = Solution().strStr(haystack, needle);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}