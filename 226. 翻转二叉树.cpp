
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)return nullptr;
        auto l = root->left;
        root->left = root->right;
        root->right = l;
        if (root->left != nullptr)invertTree(root->left);
        if (root->right != nullptr)invertTree(root->right);
        return root;
    }
};