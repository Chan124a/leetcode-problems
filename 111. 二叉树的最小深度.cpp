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
    void de(TreeNode* root, int depth, int& ans) {
        if (root == NULL)return;
        if (root->left == NULL && root->right == NULL) {
            if (depth < ans)ans = depth;
            return;
        }
        if (depth >= ans)return;
        de(root->left, depth + 1, ans);
        de(root->right, depth + 1, ans);
        return;
    }
    int minDepth(TreeNode* root) {
        if (root == NULL)return 0;
        int ans = INT_MAX;
        de(root, 1, ans);
        return ans;
    }
};