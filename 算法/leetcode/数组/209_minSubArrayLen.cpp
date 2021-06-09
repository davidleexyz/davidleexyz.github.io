#include <vector>
#include <numeric>

// 滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int start = 0, end = 0;
        int minLen = std::numeric_limits<int>::max();
        int currSum = 0;
        
        while (end < nums.size()) {
            currSum += nums[end];
            while (currSum >= target) {
                int len = end - start + 1;
                if (minLen > len) minLen = len;
                currSum -= nums[start];
                start++;
            }
            end++;
        }
        return minLen == std::numeric_limits<int>::max() ? 0 : minLen;
    }
};