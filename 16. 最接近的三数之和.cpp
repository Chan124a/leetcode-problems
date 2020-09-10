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
    int threeSumClosest(vector<int>& nums, int target) {
        long long dis = LLONG_MAX;
        int ans;
        int n = nums.size();
        if (n < 3)return {};
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n) {
            //if (nums[i] > target)break;
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                long long x = static_cast<long long>(nums[i]);
                long long y = static_cast<long long>(nums[left]);
                long long z = static_cast<long long>(nums[right]);
                if (x + y +z>target) {
                    if (abs(x + y + z-target) < dis) {
                        dis = abs(x + y + z - target);
                        ans = x + y + z;
                    }
                    right--;
                }
                else if (x + y +z< target) {
                    if (abs(x + y + z - target) < dis) {
                        dis = abs(x + y + z - target);
                        ans = x + y + z;
                    }
                    left++;
                }
                else {
                    ans = x + y + z;
                    return ans;
                    while (left < right && nums[left] == nums[left + 1])left++;
                    while (left < right && nums[right] == nums[right - 1])right--;
                    left++;
                    right--;
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1])i++;
            i++;
        }
        return ans;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().threeSumClosest(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}