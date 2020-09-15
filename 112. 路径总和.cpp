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
    void search(TreeNode* root, int sum, int temp,bool& flag) {
        if (root == NULL)return;
        if (flag)return;
        temp += root->val;
        if (root->left == NULL && root->right == NULL) {
            if (temp == sum)flag = true;
            return;
        }
        search(root->left, sum, temp, flag);
        search(root->right, sum, temp, flag);
        return;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        bool ans = false;
        search(root, sum, 0, ans);
        return ans;
    }
};