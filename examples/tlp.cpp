#include <iostream>

template <typename T>
struct PointerOf {
  using result = T*;
};

template <int N, typename T, template <typename> class Func>
struct Times {
  using result = Func<typename Times<N-1, T, Func>::result>::result;
};

template <typename T, template <typename> class Func>
struct Times<1, T, Func> {
  using result = Func<T>::result;
};