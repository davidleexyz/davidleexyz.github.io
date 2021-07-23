#include "tensor.h"
#include <iostream>

using namespace miniflow;

int main(int argc, char* argv[]) {
  Tensor<float> tensor1({1,2}, {6,6});
  std::cout << tensor1[0] << ", " << tensor1[1] << "\n";

  Tensor<float> tensor2({3, 4});
  std::cout << tensor2[0] << "," << tensor2[1] << "\n";

  auto shape = tensor1.shape();
  for (auto s : shape) {
    std::cout << s << ", ";
  }

  Tensor<float> tensor3(tensor1);
  std::cout << tensor3[0] << "," << tensor3[1] << "\n";

  tensor3[0] = 1;

  std::cout << tensor1[0] << "," << tensor1[1] << "\n";

  return 0;
}