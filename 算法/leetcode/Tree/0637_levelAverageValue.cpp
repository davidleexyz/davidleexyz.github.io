#include <vector>
#include <queue>

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::vector<double> res;
        if (root) q.push(root);

        while (!q.empty()) {
            int size = q.size();
            double sum = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                sum += node->val;
            }
            res.push_back(sum / size);
        }
        return res;
    }
};