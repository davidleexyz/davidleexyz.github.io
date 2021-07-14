class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;

        if (left && !right) return false;
        if (!left && right) return false;

        if (left->val != right->val) return false;
        else {
            return compare(left->left, right->right)
            && compare(left->right, right->left);
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return compare(root->left, root->right);
    }
};