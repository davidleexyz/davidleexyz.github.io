/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include <vector>
#include <queue>

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        std::queue<Node*> q;
        std::vector<std::vector<int>> res;
        if (root) q.push(root);

        while (!q.empty()) {
            int size = q.size();
            std::vector<int> value;
            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();

                for (int j = 0; j < node->children.size(); ++j) {
                    q.push(node->children[j]);
                }
                value.push_back(node->val);
            }
            res.push_back(value);
        }

        return res;
    }
};