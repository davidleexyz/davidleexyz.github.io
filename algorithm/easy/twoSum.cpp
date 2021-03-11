#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// method one:
// 1. sort
// 2. left and right pointer scan
// 3. if left + right < target then left++ or right--

// method two:
// hash
class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      int remain = target - nums[i];
      auto iter = map.find(remain);
      if (iter != map.end()) {
        return {iter->second, i};
      } else {
        map.insert({nums[i], i});
      }
    }
  }
};

int main()
{
  Solution s;
  std::vector<int> nums{3,1,3};
  int target = 6;
  auto result = s.twoSum(nums, target);
  std::cout << "[" << result[0] << ", " << result[1] << "]" << "\n";
  return 0;
}