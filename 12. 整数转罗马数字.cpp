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
    string ge(int x) {
        string res = "";
        if (x == 4)return "IV";
        if (x == 9)return "IX";
        else {
            if (x >= 5) {
                res += "V";
                x -= 5;
            }
            for (int i = 0; i < x; i++)
            {
                res += "I";
            }
            return res;
        }
    }
    string shi(int x) {
        string res = "";
        if (x == 4)return "XL";
        if (x == 9)return "XC";
        else {
            if (x >= 5) {
                res += "L";
                x -= 5;
            }
            for (int i = 0; i < x; i++)
            {
                res += "X";
            }
            return res;
        }
    }
    string bai(int x) {
        string res = "";
        if (x == 4)return "CD";
        if (x == 9)return "CM";
        else {
            if (x >= 5) {
                res += "D";
                x -= 5;
            }
            for (int i = 0; i < x; i++)
            {
                res += "C";
            }
            return res;
        }
    }
    string intToRoman(int num) {
        vector<int> n;
        int x = num;
        while (x!=0)
        {
            n.push_back(x % 10);
            x /= 10;
        }
        
        int len = n.size();
        if (len < 2) {
            return ge(n[0]);
        }
        else if (len < 3) {
            return shi(n[1])+ge(n[0]);
        }
        else if (len < 4) {
            return bai(n[2]) + shi(n[1]) + ge(n[0]);
        }
        else{
            string res = "";
            for (int i = 0; i < n[3]; i++)
            {
                res += "M";
            }
            return res+ bai(n[2]) + shi(n[1]) + ge(n[0]);
        }
    }
};
int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}