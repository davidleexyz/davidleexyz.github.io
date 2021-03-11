#include <vector>
#include <iostream>

// hints: sliding window
class Solution {
public:
  template <typename T>
  T maxSumOfSubarray(std::vector<T> &array, int k) {

  }
};

int main()
{
  Solution s;
  std::vector<int> array = {2, 1, 5, 1, 3, 2};
  int k = 3;

  auto result = s.maxSumOfSubarray(array, k);

  return 0;
}