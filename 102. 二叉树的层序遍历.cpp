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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void order(TreeNode* root, vector<vector<int>>& res, int depth) {
        if (root == NULL)return;
        if (root->left != NULL) {
            if (res.size() < depth + 2)res.push_back(vector<int> {root->left->val});
            else res[depth + 1].push_back(root->left->val);
        }
        if (root->right != NULL) {
            if (res.size() < depth + 2)res.push_back(vector<int> {root->right->val});
            else res[depth + 1].push_back(root->right->val);
        }
        if (root->left != NULL) {
            order(root->left, res, depth + 1);
        }
        if (root->right != NULL) {
            order(root->right, res, depth + 1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)return {};
        vector<vector<int>> res;
        //queue<int> q;
        //res[0].push_back(root->val);
        res.push_back(vector<int>{root->val});
        order(root, res, 0);
        return res;
    }
};