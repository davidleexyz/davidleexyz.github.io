#include <vector>
#include <queue>

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::vector<int> res;
        if (root != nullptr) q.push(root);

        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

                if (i == size-1) {
                    res.push_back(node->val);
                }
            }
        }

        return res;
    }
};