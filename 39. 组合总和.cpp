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
    void dfs(vector<int>candidates, vector<vector<int>>& ans, vector<int>& temp, int target, int idex, int sum) {
        if (sum == target) {
            //temp.push_back(candidates[idex]);
            ans.push_back(temp);
            //temp.pop_back();
            return;
        }
        if (sum > target)return;
        //if (sum + candidates[i] > target)break;
        for (int i = idex; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            if(sum+candidates[i]<=target)
            dfs(candidates, ans, temp, target, i, sum + candidates[i]);
            temp.pop_back();
            if (sum + candidates[i] > target)break;
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0)return {};
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(candidates, ans, temp, target, 0, 0);
        return ans;
    }
};
// author:rmokerone



int main() {
    vector<int> candidates = { 2,3,6,7 };
    vector<vector<int>> a = Solution().combinationSum(candidates, 7);
}