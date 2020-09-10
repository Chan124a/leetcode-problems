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
    void inOrder(TreeNode* root, TreeNode*& pre, int& curTimes,
        int& maxTimes, vector<int>& res) {
        if (!root) return;
        inOrder(root->left, pre, curTimes, maxTimes, res);
        if (pre)
            curTimes = (root->val == pre->val) ? curTimes + 1 : 1;
        if (curTimes == maxTimes)
            res.push_back(root->val);
        else if (curTimes > maxTimes) {
            res.clear();
            res.push_back(root->val);
            maxTimes = curTimes;
        }
        pre = root;
        inOrder(root->right, pre, curTimes, maxTimes, res);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        TreeNode* pre = NULL;
        int curTimes = 1, maxTimes = 0;
        inOrder(root, pre, curTimes, maxTimes, res);
        return res;
    }
};
//下面是我写的错误答案，我的错误在于没对递归中pre的初试值设置好。pre应该设置为指针类型，然后初始值为NULL，这样才好进行判断。
//class Solution {
//public:
//    void dep(TreeNode *root,int c_count,int m_count,int &pre,vector<int> &res){
//        if (root == NULL)return;
//        dep(root->left, c_count, m_count, pre, res);
//        if (root->val == pre)c_count++;
//        else c_count = 1;
//        if (c_count == m_count)res.push_back(root->val);
//        if (c_count > m_count) {
//            res.clear();
//            res.push_back(root->val);
//            m_count = c_count;
//        }
//        pre = root->val;
//        dep(root->right, c_count, m_count, pre, res);
//    }
//    vector<int> findMode(TreeNode* root) {
//       
//       vector<int>res;
//       if (root == NULL)return res;
//       dep(root,0, 0, root->val, res);
//       return res;
//    }
//};
void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
        }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
        }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);

        vector<int> ret = Solution().findMode(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}