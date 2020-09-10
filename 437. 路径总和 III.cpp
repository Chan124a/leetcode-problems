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
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int dep(TreeNode* root, int sum) {
        if (root==NULL)return 0;
        sum = sum - root->val;
        if (sum == 0)return 1 + dep(root->left, sum) + dep(root->right, sum);
        else return dep(root->left, sum) + dep(root->right, sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)return 0;
        int count = dep(root, sum);
        int a = pathSum(root->left, sum);
        int b = pathSum(root->right, sum);
        return count + a + b;
    }
};