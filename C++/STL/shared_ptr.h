#ifndef MYSTL_SHARED_PTR_H
#define MYSTL_SHARED_PTR_H

namespace mystl {

template <typename T>
class shared_ptr {
public:
  shared_ptr(shared_ptr &rhs);
  ~shared_ptr();

  shared_ptr operator=(shared_ptr &rhs);
private:
  T* base;
  int* count;
};

};
#endif