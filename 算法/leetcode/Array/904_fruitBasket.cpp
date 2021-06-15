#include <vector>

// 滑动窗口 Medium
class Solution {
public:
    int totalFruit(std::vector<int>& tree) {
        int start = 0, end = 0;
        int maxLen = 0, curLen = 0;
        int leftVal = -1, rightVal = -1;
        while (end < tree.size()) {
            if (tree[end] == leftVal || tree[end] == rightVal) {
                curLen = end - start + 1;
            } else {
                if (leftVal == -1 && rightVal == -1) {
                    leftVal = tree[end];
                    start = end;
                } else if (rightVal == -1) {
                    rightVal = tree[end];
                } else {
                    leftVal = tree[end-1];
                    rightVal = tree[end];
                    int i = end - 1;
                    while (i > start) {
                        if (tree[i-1] == leftVal) {
                            i--;
                        } else {
                            break;
                        }
                    }
                    start = i;
                }
                curLen = end - start + 1;
            }
            if (maxLen < curLen) { 
                maxLen = curLen;
            }
            end++;
        }
        return maxLen;
    }
};