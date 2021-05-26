#ifndef MY_STL_VECTOR_H
#define MY_STL_VECTOR_H

#include <iterator>
#include "iterator.h"

namespace mystl {

template <typename T>
class vector {
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
  vector();
  vector(iterator begin, iterator end);
  vector(const vector& v); //copy constructor
  vecotr(vector&& v); //move constructor
  vector(iterator begin, size_type size);
  vector(std::initializer_list<value_type>& list);
  ~vector();

  vector& operator=(const vector& v); //copy assignment
  vector& operator=(vector&& v); //move assignment
  reference operator[](size_type i);
};

};

#endif