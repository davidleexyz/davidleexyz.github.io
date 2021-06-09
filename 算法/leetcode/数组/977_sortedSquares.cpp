#include <vector>

// Medium
class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> ret;
        if (nums[0] >= 0) {
            for (auto val : nums) {
                ret.push_back(val*val);
            }
            return ret;
        }

        if (nums[nums.size()-1] < 0) {
            for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
                ret.push_back(*it * *it);
            }
            return ret;
        }
        
        int div = 0;
        for (; div < nums.size(); ++div) {
            if (nums[div] >= 0) {
                break;
            }
        }

        // 0 ~ div-1  div ~ len-1
        int left = div-1;
        int right = div;

        while (left >= 0 || right <= nums.size()-1) {
            if (nums[left] * nums[left] <= nums[right] * nums[right]) {
                ret.push_back(nums[left] * nums[left]);
                left--;
            } else {
                ret.push_back(nums[right] * nums[right]);
                right++;
            }

            if (left < 0) {
                while (right < nums.size()) {
                    ret.push_back(nums[right] * nums[right]);
                    right++;
                }
            }

            if (right > nums.size()-1) {
                while (left >= 0) {
                    ret.push_back(nums[left] * nums[left]);
                    left--;
                }
            }
        }
        return ret;
    }
};