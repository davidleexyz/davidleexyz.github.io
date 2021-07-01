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
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> vec;
        preorder(root, vec);
        return vec;
    }

    void preorder(TreeNode* root, vector<int> &vec) {
        if (root == nullptr) return;

        vec.push_back(root->val);
        preorder(root->left, vec);
        preorder(root->right, vec);
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> stack;
        std::vector<int> vec;
        if (root == nullptr) return vec;

        stack.push(root);
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            vec.push_back(node->val);
            if (node->right) {
                stack.push(node->right);
            }

            if (node->left) {
                stack.push(node->left);
            }
        }
        return vec;
    }
};