#include <vector>
#include <iostream>

// hints: sliding window
class Solution {
public:
  template <typename T>
  T maxSumOfSubarray(std::vector<T> &array, int k) {
    T sum = static_cast<T>(0);
    for (int i = 0; i < k; ++i) {
      sum += array[i];
    }

    T max = sum;
    for (int i = k; i < array.size(); ++i) {
      sum = sum - array[i-k] + array[i];
      if (max < sum) {
        max = sum;
      }
    }

    return max;
  }
};

int main()
{
  Solution s;
  std::vector<int> array = {-2, 1, 5, 1, 3, 2, 10, -8, 2, 4, 5, 1};
  int k = 4;

  auto result = s.maxSumOfSubarray(array, k);
  std::cout << "max sum of subarray: " << result << "\n";
  return 0;
}