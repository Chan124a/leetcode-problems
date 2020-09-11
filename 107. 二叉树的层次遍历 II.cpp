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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL)return{};
        vector<vector<int>> ans;
        queue<TreeNode*> qu;
        int count = 1, next_count = 2;
        qu.push(root);
        while (!qu.empty())
        {
            vector<int> temp;
            next_count = 2 * count;
            while (count != 0) {
                TreeNode* t = qu.front();
                qu.pop();
                temp.push_back(t->val);
                if (t->left != NULL)qu.push(t->left);
                else next_count--;
                if (t->right != NULL)qu.push(t->right);
                else next_count--;
                count--;
            }
            ans.push_back(temp);
            count = next_count;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};