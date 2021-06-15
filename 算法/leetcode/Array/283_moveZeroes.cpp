#include <vector>

// 左指针指向已处理元素的末尾 右指针指向待处理节点的开头
// 在left和right指针之间都是0
class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right]) {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
                left++;
            }
            right++;
        }
    }
};