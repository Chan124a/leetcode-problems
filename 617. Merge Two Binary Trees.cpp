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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2)return NULL;
        if (!t1)return t2;
        if (!t2)return t1;
        TreeNode* p = t1,*q=t2;
        p->val = p->val + q->val;
        p->left = mergeTrees(p->left, q->left);
        p->right = mergeTrees(p->right, q->right);
        return t1;
    }
};