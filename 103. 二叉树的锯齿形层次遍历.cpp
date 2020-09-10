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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)return {};
        stack<TreeNode*> st;
        queue<TreeNode*>qu;
        vector<vector<int>> ans;
        st.push(root);
        bool flag = true;
        while (!st.empty())
        {
            while (!st.empty()) {
                qu.push(st.top());
                st.pop();
            }
            vector<int> temp;
            while (!qu.empty())
            {
                auto t = qu.front();
                qu.pop();
                temp.push_back(t->val);
                if (flag) {
                    if (t->left != NULL)st.push(t->left);
                    if (t->right != NULL)st.push(t->right);
                }
                else {
                    if (t->right != NULL)st.push(t->right);
                    if (t->left != NULL)st.push(t->left);
                }
            }
            ans.push_back(temp);
            flag = !flag;
        }
        return ans;
    }
};