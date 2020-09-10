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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int,int> num;
        for (int i = 0; i < nums.size(); i++)
        {
            num[nums[i]]++;
        }
        vector<vector<int>> ans = { {} };
        for (auto t : num) {
            int n = ans.size();
            for (int i = 0; i < n; i++) {
                vector<int> temp = ans[i];
                for (int j = 0; j < t.second; j++)
                {
                    temp.push_back(t.first);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums = { 1,2,2 };
    vector<vector<int>> ans = Solution().subsetsWithDup(nums);
    return 1;
}