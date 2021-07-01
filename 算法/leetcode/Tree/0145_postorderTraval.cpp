/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        traversal(root, vec);
        return vec;
    }

    void traversal(TreeNode* root, vector<int> &vec) {
        if (root == nullptr) return;

        traversal(root->left, vec);
        traversal(root->right, vec);
        vec.push_back(root->val);
    }
};

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> vec;
        if (root == nullptr) return vec;

        std::stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            vec.push_back(node->val);
            if (node->left) stack.push(node->left);
            if (node->right) stack.push(node->right);
        }
        std::reverse(vec.begin(), vec.end());
        return vec;
    }
};