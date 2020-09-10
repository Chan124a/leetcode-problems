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
    int verify(long long x,bool flag) {
        if (!flag&&x > INT_MAX)return 1;
        else if (flag&&-x < INT_MIN)return -1;
        else return 0;
    }
    int myAtoi(string str) {
        int n = str.size();
        if (!n)return 0;
        int i = 0;
        bool flag = false;
        while (str[i]==' ')
        {
            i++;
        }
        if (i == n)return 0;
        if (str[i] == '+') {
            if (n == 1)return 0;
            if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))return 0;
            i++;
        }
        if (str[i] == '-') {
            if (n == 1)return 0;
            if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))return 0;
            flag = true;
            i++;
        }
        if (!(str[i] >= '0' && str[i] <= '9'))return 0;
        long long res=0;
        /*if (str[i] == '-') {
            if(i + 1 < n)
                res = str[i+1] - '0';
            flag = true;
            i++;
        }
        else
        {
            res = str[i] - '0';
        }
        i++;*/
        while (i<n&&str[i]>='0'&&str[i]<='9')
        {
            res = res * 10 + str[i++]-'0';
            int p = verify(res, flag);
            if (p == -1)return INT_MIN;
            else if (p == 1)return INT_MAX;
        }
        if (flag)return -res;
        else return res;
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
        string str = stringToString(line);

        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}