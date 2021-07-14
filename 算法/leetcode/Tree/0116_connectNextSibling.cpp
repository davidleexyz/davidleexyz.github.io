#include <queue>

class Solution {
public:
    Node* connect(Node* root) {
        std::queue<Node*> q;
        if (root) q.push(root);

        Node* pre;
        while (!q.empty()) {
            int size = q.size();
            pre = nullptr;
            for(int i = 0; i < size; ++i) {
                Node* cur = q.front();
                q.pop();
                if (pre) {
                    pre->next = cur;
                }

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);

                pre = cur;
            }
        }
        return root;        
    }
};