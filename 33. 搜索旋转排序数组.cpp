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
//下面这个是我自己写的，可以通过测试
//执行用时：0 ms, 在所有 C++ 提交中击败了100.00 %的用户
//内存消耗：10.7 MB, 在所有 C++ 提交中击败了90.69 %的用户
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left / 2.0 + right / 2.0;
            if (nums[mid] == target)return mid;
            if (target >= nums[0]) {//target在数组前半部分
                if (nums[mid] < nums[0])right = mid - 1;//mid落在数组后半部分
                else {
                    if (nums[mid] > target)right = mid - 1;
                    else left = mid + 1;
                }
            }
            else {//target在数组后半部分
                if (nums[mid] >= nums[0])left = mid + 1;//mid落在数组前半部分
                else {
                    if (nums[mid] > target)right = mid - 1;
                    else left = mid + 1;
                }
            }
        }
        return -1;
    }
};
//下面这个是参考答案
//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        if (nums.size() == 0)return -1;
//        int left = 0, high = nums.size() - 1;
//        while (left < high) {
//            int mid = (left + high) / 2;
//            if (nums[mid] == target)return mid;
//            if (nums[left] <= nums[mid] && nums[left] <= target && target <= nums[mid])high = mid;
//            else if (nums[left] > nums[mid] && (target <= nums[mid] || target >= nums[left]))high = mid;
//            else left = mid+1;
//        }
//        if (nums[left] == target)return left;
//        else return -1;
//    }
//};
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().search(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}