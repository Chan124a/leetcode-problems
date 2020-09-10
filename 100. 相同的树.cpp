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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)return true;
        else if (p == NULL && q != NULL)return false;
        else if (p != NULL && q == NULL)return false;
        if (p->val == q->val)return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else return false;
    }
};