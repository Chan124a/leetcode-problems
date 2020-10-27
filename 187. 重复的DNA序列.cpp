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
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        unordered_map<string,int> res;
        vector<string> ans;
        for (int  i = 0; i <= len-10; i++)
        {
            string temp = s.substr(i, 10);
            if (res.count(temp)&&res[temp]==1)ans.push_back(temp);
            res[temp]++;
        }
        return ans;
    }
};
//class Solution {
//public:
//    vector<string> findRepeatedDnaSequences(string s) {
//        //对应二进制00, 01, 10, 11.那么10个组合只要20位就够了。
//        unordered_map<char, int> m{ {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} };
//        vector<string> res;
//        bitset<1 << 20> s1, s2; //那么所有组合的值将在0到(1 << 20 - 1)之间
//        int val = 0, mask = (1 << 20) - 1; //mask等于二进制的20个1
//        //类似与滑动窗口先把前10个字母组合
//        for (int i = 0; i < 10; ++i) val = (val << 2) | m[s[i]];
//        s1.set(val); //置位
//        for (int i = 10; i < s.size(); ++i) {
//            val = ((val << 2) & mask) | m[s[i]]; //去掉左移的一个字符再加上一个新字符
//            if (s2.test(val)) continue; //出现过两次跳过
//            if (s1.test(val)) {
//                res.push_back(s.substr(i - 9, 10));
//                s2.set(val);
//            }
//            else s1.set(val);
//        }
//        return res;
//    }
//};
int main() {
    string s = "AAAAAAAAAAAAA";
    vector<string> ans = Solution().findRepeatedDnaSequences(s);
    return 0;
}