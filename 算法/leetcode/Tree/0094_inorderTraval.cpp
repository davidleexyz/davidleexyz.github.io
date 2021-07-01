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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> vec;
        traversal(root, vec);
        return vec;
    }

    void traversal(TreeNode* root, std::vector<int> &vec) {
        if (root == nullptr) return;

        traversal(root->left, vec);
        vec.push_back(root->val);
        traversal(root->right, vec);
    }
};

// cur指针访问节点, stack保存节点
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> vec;
        std::stack<TreeNode*> stack;
        TreeNode* cur = root;
        while (cur != nullptr || !stack.empty()) {
            if (cur != nullptr) {
                stack.push(cur);
                cur = cur->left;
            } else {
                cur = stack.top();
                stack.pop();
                vec.push_back(cur->val);
                cur = cur->right;
            }
        }
        return vec;
    }
};