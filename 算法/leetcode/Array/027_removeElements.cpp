#include <vector>

// 删除数组中指定的元素 (two pointers)

// start 保存不重复的元素
// end 从结尾遍历数组元素
// 直到start >= end 结束
class Solution {
  int removeElements(std::vector<int> nums, int val) {
    int start = 0, end = nums.size();
    while (start < end) {
      if (nums[start] == val) {
        nums[start] = nums[end-1];
        end--;
      } else {
        start++;
      }
    }
    return start;
  }
};