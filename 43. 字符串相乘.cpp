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
    string mul(string num1, char x) {
        int a = x - '0';
        int idex = 0;
        string ans(num1.size() + 1, '0');
        for (int i =num1.size()-1; i>=0; i--)
        {
            int b = num1[i] - '0';
            int c = a * b+idex;
            idex = c / 10;
            if (c > 9) {
                c = c % 10;
            }
            ans[i + 1] += c ;
        }
        if (idex != 0) {
            ans[0] += idex; 
            return ans;
        }
        else return ans.substr(1);
    }
    string add(string s1, string s2) {
        string a1, a2;
        if (s1.size() >= s2.size()) {
            a1 = s1;
            a2 = s2;
        }
        else {
            a1 = s2;
            a2 = s1;
        }
        int x = a1.size() - a2.size();
        int idex = 0;
        for (int i = a2.size() - 1; i >= 0; i--) {
            int a = a1[i+x] - '0';
            int b = a2[i] - '0';
            int c = a + b+idex;
            idex = c / 10;
            if (c > 9)c -= 10;
            a1[i + x] = c+'0';
        }
        int i = a1.size() - a2.size() - 1;
        while (idex!=0)
        {
            if (i >= 0) {
                int a = a1[i] - '0';
                int c = a + idex;
                idex = c / 10;
                if (c > 9)c -= 10;
                a1[i] = c + '0';
                i--;
            }else{
                a1=to_string(idex) + a1;
                break;
            }
        }
        return a1;
    }
    string multiply(string num1, string num2) {
        if ((num1.size() == 1 && num1[0] == '0') || (num2.size() == 1 && num2[0] == '0'))return "0";
        string ling;
        string ans;
        for (int i = num2.size()-1; i>=0; i--)
        {
            string temp = mul(num1, num2[i]);
            temp += ling;
            ans = add(temp, ans);
            ling += "0";
        }
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
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);

        string ret = Solution().multiply(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}