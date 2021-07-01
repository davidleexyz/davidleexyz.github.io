#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        if (root == nullptr) return std::vector<std::vector<int>>();
        q.push(root);
        std::vector<std::vector<int>> res;
        std::vector<int> temp;
        while(!q.empty()) {
            int size = q.size();
            temp.clear();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                temp.push_back(node->val);
            }
            res.push_back(temp);
        }

        return res;
    }
};