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


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& temp, int sum, int &S,TreeNode* root) {
        if (root == NULL)return;
        S += root->val;
        temp.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (S == sum) {
                ans.push_back(temp);
            }
        }
        dfs(temp, sum, S, root->left);
        dfs(temp, sum, S, root->right);
        S -= root->val;
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        int S = 0;
        dfs(temp, sum, S, root);
        return ans;
    }
};