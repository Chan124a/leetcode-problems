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
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <pair>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    pair<int, int> helper(TreeNode* root) {
        if (root == NULL)return make_pair(0,0);
        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);

        return make_pair(root->val + left.second + right.second, max(left.first, left.second) + max(right.first, right.second));
    }
    int rob(TreeNode* root) {
        pair<int, int> ans = helper(root);
        return max(ans.first, ans.second);
    }
};
