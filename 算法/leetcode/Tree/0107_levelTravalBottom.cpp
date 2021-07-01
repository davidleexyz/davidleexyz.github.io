#include<vector>
#include<queue>

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        std::queue<TreeNode*> q;
        if (root != nullptr) q.push(root);
        vector<vector<int>> res;
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

                temp.push_back(node->val);
            }
            res.push_back(temp);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};