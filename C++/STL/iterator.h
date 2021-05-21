#ifndef MYSTL_ITERATOR_H
#define MYSTL_ITERATOR_H

#include <cstddef> // ptrdiff_t
#include <type_traits>

#include "type_traits.h"

namespace mystl {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirect_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirect_iterator_tag {};

template <typename Category,
 typename T, typename Distance = ptrdiff_t, typename Reference = T&, typename Pointer = T*>
struct Iterator {
  using iterator_category = Category;
  using value_type = T;
  using difference_type = Distance;
  using reference = Reference;
  using pointer = Pointer;
};

template <typename, bool>
struct iterator_traits_impl {};

template <typename Iterator, bool>
struct iterator_traits_impl<Iterator, true> {
  using iterator_category = typename Iterator::iterator_category;
  using value_type = typename Iterator::value_type;
  using difference_type = typename Iterator::difference_type;
  using reference = typename Iterator::reference;
  using pointer = typename Iterator::pointer;
};

template <typename Iterator>
struct iterator_traits : iterator_traits_impl<Iterator,
 std::is_convertible<typename Iterator::iterator_category, input_iterator_tag>::value ||
 std::is_convertible<typename Iterator::iterator_category, output_iterator_tag>::value> {
};

// 偏特化版本
template <typename T>
struct iterator_traits<T*> {
  using iterator_category = random_access_iterator_tag;
  using value_type = T;
  using difference_type = ptrdiff_t;
  using reference = T&;
  using pointer = T*;
};

template <typename T>
struct iterator_traits<const T*> {
  using iterator_category = random_access_iterator_tag;
  using value_type = T;
  using difference_type = ptrdiff_t;
  using reference = T&;
  using pointer = T*;
};

// 后面就可以定义iterator的萃取模板函数了
template <typename Iterator>
typename iterator_traits<Iterator>::iterator_category
category(Iterator&) {
  typename iterator_traits<Iterator>::iterator_category Category;
  return Category();
};

// value_type
// difference_type
// reference
// pointer

};

#endif