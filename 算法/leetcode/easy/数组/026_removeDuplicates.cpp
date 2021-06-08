#include <vector>

// 删除有序数组中重复的元素
class Solution {
  int removeDumplicates(std::vector<int> nums) {
    if (nums.size() == 0) return 0;
    int fast = 0, slow = 0;
    for (; fast < nums.size(); ++fast) {
      if (nums[slow] == nums[fast]) {
        continue;
      } else {
        slow++;
        nums[slow] = nums[fast];
      }
    }
    return slow+1;
  }
};