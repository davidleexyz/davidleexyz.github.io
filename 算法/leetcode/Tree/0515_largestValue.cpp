#include <vector>
#include <queue>
#include <limits>

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        std::vector<int> res;
        std::queue<TreeNode*> q;
        if (root) q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int max = std::numeric_limits<int>::min();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (max < node->val) max = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(max);
        }
        return res;
    }
};