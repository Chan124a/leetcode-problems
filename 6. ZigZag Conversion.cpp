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
    string convert(string s, int numRows) {
        if (numRows == 1)return s;
        int n = s.size();
        int row = min(n, numRows);
        vector<string> res(row);
        bool down = false;
        int cur_row = 0;
        for (int i = 0; i < n; i++)
        {
            res[cur_row] += s[i];
            if (!down)
            {
                cur_row++;
            }
            else {
                cur_row--;
            }
            if (cur_row == 0 || cur_row == row-1)down = !down;
        }
        for (int i = row-2; i >=0; i--)
        {
            res[i] += res[i+1];
        }
        return res[0];
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);

        string ret = Solution().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}