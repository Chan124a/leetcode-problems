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
//下面的解法也是可以的，但是超出时间限制了
//class Solution {
//public:
//    bool can(vector<int> nums, int idex,vector<int> cans) {
//        if (nums[idex] >= nums.size() - 1 - idex)return true;
//        for (int j = cans.size()-1; j>=0; j--)
//        {
//            if (nums[idex] >= cans[j] - idex)return true;
//        }
//        return false;
//    }
//    bool canJump(vector<int>& nums) {
//        int n = nums.size();
//        if (n == 0)return false;
//        vector<int> cans;
//        for (int i = n-1; i >=0; i--)
//        {
//            if (can(nums, i, cans))cans.push_back(i);
//        }
//        if (cans[cans.size() - 1] == 0)return true;
//        else return false;
//    }
//};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int j = -1;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] + i > j)j = nums[i] + i;
            if (j < i + 1)return false;
        }
        if (j >= nums.size() - 1)return true;
        else return false;
    }
};
void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
        }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
        }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution().canJump(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}