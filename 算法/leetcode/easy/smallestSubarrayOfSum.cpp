#include <vector>
#include <iostream>
#include <limits>

// hints: sliding window
// 1. find suitable window 2. decrease windows size 3. calc length 4. goto 1
// startPos, endPos

class Solution {
public:
  template <typename T>
  int smallestSubarrayOfSum(std::vector<T> &array, T sum) {
    int minLength = std::numeric_limits<int>::max();
    int windowSum = 0;
    int windowStart = 0;
    for (int i = 0; i < array.size(); ++i) {
      windowSum += array[i];
      while (windowSum >= sum) {
        minLength = std::min(minLength, i - windowStart + 1);
        windowSum -= array[windowStart];
        windowStart++;
      }
    }
    return minLength;
  }
};

int main()
{
  Solution s;

  std::vector<int> int_array = {2,1,5,2,3,2};
  std::vector<float> float_array = {2,1,5,2,8};
  int int_sum = 7;
  float float_sum = 7;
  auto result0 = s.smallestSubarrayOfSum(int_array, int_sum);
  auto result1 = s.smallestSubarrayOfSum(float_array, float_sum);
  std::cout << "smallest subarray lenght of sum: " << result0 << ", " << result1 << "\n";
  return 0; 
}