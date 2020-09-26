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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, int sum) {
        if (root == NULL)return;
        sum = sum * 10 + root->val;
        if (root->left == NULL && root->right == NULL)ans += sum;
        dfs(root->left, sum);
        dfs(root->right, sum);
        return;
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};