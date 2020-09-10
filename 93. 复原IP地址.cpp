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
#include <map>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        string cur = s;
        int n = s.size();
        helper(0, -1, n, s, cur);
        return ans;
    }
    void helper(int point_count,int last_point,int n,string &s,string &cur) {
        if (point_count == 3) {
            if (check(last_point + 1, n - 1, s)) {
                ans.push_back(cur);
            }
            return;
        }
        for (int i = last_point+1; i < n-1; i++)
        {
            if (check(last_point + 1, i, s)) {
                cur.insert(cur.begin() + i + point_count + 1, '.');
                helper(point_count + 1, i,n, s, cur);
                cur.erase(i + point_count + 1, 1);
            }
        }
        return;
    }
    bool check(int left, int right, string& s) {
        int num = 0;
        for (int i = left; i <=right; i++)
        {
            if (s[left] == '0' && left != right)return false;
            num = num * 10 + s[i] - '0';
            if (num > 255)return false;
        }
        return true;
    }
};
int main() {
    string s = "1111";
    vector<string> ans = Solution().restoreIpAddresses(s);
    return 0;
}
//下面是c++暴力四层循环解法
//class Solution {
//public:
//    bool check(string t) {
//        if (stoi(t,0,2) <= 255) {
//            if(t[0]!='0'||(t[0]=='0'&&t.size()==1))return true;
//        }
//        return false;
//    }
//    vector<string> restoreIpAddresses(string s) {
//        vector<string> res;
//        int n=s.size();
//        for (int a = 0; a < n; a++)
//            for(int b=0;b<n;b++)
//                for(int c=0;c<n;c++)
//                    for (int d = 0; d < n; d++) {
//                        if (a + b + c + d == n) {
//                            string s1 = s.substr(0, a);
//                            string s2 = s.substr(a, b);
//                            string s3 = s.substr(a+b, c);
//                            string s4 = s.substr(a+b+c, d);
//                            /*不能保障截取的字符串转成int后与输入字符串长度相同
//                            * 如：字符串010010，a=1，b=1，c=1，d=3，对应字符串0，1，0，010
//                            * 转成int后seg1=0，seg2=1，seg3=0，seg4=10
//                            * //所以需要判断if (ip.length() == s.length() + 3)
//                            */
//                            if (check(s1) && check(s2) && check(s3) && check(s4)) {
//                                string temp = s1 + '.' + s2 + '.' + s3 + '.' + s4;
//                                res.push_back(temp);
//                            }
//                        }
//                    }
//        return res;
//    }
//};

