#ifndef MINIFLOW_TENSOR_H
#define MINIFLOW_TNESOR_H

#include <vector>
#include <initializer_list>
#include <type_traits>
#include <numeric>
#include <cassert>

namespace miniflow {

template <typename T>
class Tensor {
  static_assert(std::is_arithmetic<T>::value, "Tensor type must POD");
public:
  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using self_type = Tensor;
  using vector_type = std::vector<T>;
  using shared_vector = std::shared_ptr<vector_type>;

  std::vector<int> shape_;
  shared_vector data_;

  pointer data() {
    return data_->data();
  }

  pointer begin() {
    return data();
  }

  const_pointer cbegin() const {
    return data();
  }

  pointer end() {
    return begin() + data_->size();
  }

  const_pointer cend() const {
    return begin() + data_->size();
  }

  Tensor()
    : shape_(std::vector<int>()),
      data_(std::make_shared<vector_type>()) {}

  Tensor(std::initializer_list<int> shape)
    : shape_(shape),
      data_(std::make_shared<vector_type>()) {
      int64_t size = std::accumulate(shape.begin(), shape.end(), 1, std::multiplies<int64_t>());
      data_->resize(size);
      std::fill_n(data_->begin(), size, 0);
  }

  Tensor(const std::vector<int> &shape, const std::vector<T> &data)
    : shape_(shape),
      data_(std::make_shared<vector_type>(data)) {
        assert(std::accumulate(shape.begin(), shape.end(), 1, std::multiplies<int64_t>()) == data.size());
  }
  
  Tensor(std::initializer_list<int> shape, std::initializer_list<T> data)
    : shape_(shape),
      data_(std::make_shared<vector_type>(data)) {
        assert(std::accumulate(shape.begin(), shape.end(), 1, std::multiplies<int64_t>()) == data.size());
  }
  
  Tensor(const Tensor &other) {
    shape_ = other.shape_;
    data_ = other.data_;
  }

  self_type& operator=(const Tensor &other) {
    shape_ = other.shape_;
    data_ = other.data_;
    return *this;
  }

  value_type& operator[](uint64_t index) {
    return *(begin() + index);
  }

  value_type const& operator[](uint64_t index) const {
    return *(begin() + index);
  }

  const std::vector<int>& shape() const {
    return shape_;
  }

  void reshape(std::vector<int> &new_shape) {
    auto new_size = std::accumulate(new_shape.begin(), new_shape.end(), 1, std::multiplies<int64_t>());
    auto old_size = std::accumulate(shape_.begin(), shape_.end(), 1, std::multipiles<int64_t>());
    assert(new_size == old_size);

    shape_ = new_shape;
  }
};

}

#endif