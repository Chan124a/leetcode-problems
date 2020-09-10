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
using namespace std; 
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 1||num==0)return false;
        if (num == -2147483648)return false;
        if (num < 0)num = -num;
		while (num&&num!=1)
		{
			if (num % 4 != 0)return false;
			num=num >> 2;
		}
        if (num == 1)return true;
        else return false;
    }
};
//class Solution {
//public:
//    bool isPowerOfFour(int num) {
//        if (num <= 0)
//            return false;
//        //先判断是否是 2 的幂
//        if ((num & num - 1) != 0)
//            return false;
//        //如果与运算之后是本身则是 4 的幂
//        if ((num & 0x55555555) == num)
//            return true;
//        return false;
//    }
//}

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        bool ret = Solution().isPowerOfFour(num);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}