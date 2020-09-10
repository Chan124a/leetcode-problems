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
//    vector<string> ans;
//    vector<string> sList = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//    vector<string> letterCombinations(string digits) {
//        if (digits.size() == 0)return {};
//        helper(digits, {}, 0);
//        return ans;
//    }
//    void helper(string digits, string s, int idx) {
//        if (idx == digits.size()) {
//            ans.push_back(s);
//            return;
//        }
//        int pos = digits[idx] - '0';
//        string temp = sList[pos];
//        for (int i = 0; i < temp.size(); i++)
//        {
//            helper(digits, s + temp[i], idx + 1);
//        }
//    }
//};
class Solution {
public:
    vector<string> ans;
    vector<string> sList = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" }; //字符表

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        queue<string> q;
        for (int i = 0; i < digits.size(); i++) {  // 遍历digits
            int pos = digits[i] - '0'; // 数字
            string s = sList[pos]; // 数字对应字符串
            if (i == 0) {
                string initStr;
                for (int j = 0; j < s.size(); j++) {
                    initStr = s[j];
                    q.push(initStr); // 填入单字符
                }
            }
            else {
                string fr = q.front();    // 队列首位
                while (fr.size() < i + 1) {   // 队列首位的字符串是否小于遍历digits的子串的长度
                    q.pop();            // 删除首位
                    for (int j = 0; j < s.size(); j++) {
                        q.push(fr + s[j]);
                    }
                    fr = q.front();       // 更新队列首位
                }
            }
        }
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};