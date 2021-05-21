#ifndef MY_STL_VECTOR_H
#define MY_STL_VECTOR_H

#include <iterator>
#include "iterator.h"

namespace mystl {

template <typename T>
class Vector {
public:
  // 应该从allocator中获取T类型
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using pointer = T*;
  using const_pointer = const T*;
  using size_type = size_t;
  using distance_type = diffptr_t;

  using iterator = value_type*;
  using const_iterator = const value_type*;
  using reverse_iteraotr = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const iterator>;

private:
  iterator beg_;
  iterator end_;
  iterator cap_;

public:
  Vector();
  ~Vector();

};

};

#endif