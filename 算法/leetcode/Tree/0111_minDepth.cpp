class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        if (root->left and !root->right)
            return minDepth(root->left) + 1;

        if (!root->left and root->right)
            return minDepth(root->right) + 1;
        
        return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};